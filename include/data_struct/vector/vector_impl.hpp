template <typename T>
vector<T>::vector()
: data(nullptr),
  sz(0),
  cp(0)
{ }

template <typename T>
vector<T>::vector(size_t count)
: cp(count)
{ 
  reallocate(cp);
  sz = cp;
  for(int idx = 0; idx < sz; ++idx)
    new (data + idx) T();
}

// TODO: Does T have copy ctor?
template <typename T>
vector<T>::vector(size_t count, const T& value)
: cp(count)
{ 
  reallocate(cp);
  sz = cp;
  for(int idx = 0; idx < sz; ++idx)
    new (data + idx) T(value);
}

template <typename T>
template <typename InputIter, typename>
vector<T>::vector(InputIter begin, InputIter end)
{
  for(;begin < end; ++begin)
    push_back(*begin);
}

template <typename T>
vector<T>::~vector() 
{
  for(size_t idx = 0; idx < sz; ++idx)
  {
    data[idx].~T();
  }

  if (data != nullptr)
    ::operator delete(data);
}

template <typename T>
void vector<T>::push_back(const T& value)
{
  if (cp == 0)
    reallocate(1);

  if (sz == cp)
    reallocate(2 * cp);

  new (data + sz) T(value);
  sz++;
}

template <typename T>
void vector<T>::push_back(T&& value)
{
  if (cp == 0)
    reallocate(1);

  if (sz == cp)
    reallocate(2 * cp);

  new (data + sz) T(std::move(value));
  sz++;
}

template <typename T>
template <typename... Args>
void vector<T>::emplace_back(Args&&... args)
{
  if (cp == 0)
    reallocate(1);

  if (sz == cp)
    reallocate(2 * cp);

  new (data + sz) T(std::forward<Args>(args)...);
  sz++;
}

template <typename T>
void vector<T>::clear()
{
  for(size_t idx = 0; idx < sz; ++idx)
  {
    data[idx].~T();
  }

  sz = 0;
}

template <typename T>
typename vector<T>::reference vector<T>::operator[](size_type pos)
{
  if (pos >= sz)
    throw std::out_of_range("Out of range in operator[]");

  return data[pos];
}

template <typename T>
typename vector<T>::const_reference vector<T>::operator[](size_type pos) const
{
  if (pos >= sz)
    throw std::out_of_range("Out of range in operator[]");

  return data[pos];
}

template <typename T>
typename vector<T>::size_type vector<T>::max_size() const
{
  return std::numeric_limits<difference_type>::max() / sizeof(T);
}

// doc: all iterator invalidated
template <typename T>
void vector<T>::reserve(size_t new_cap)
{
  if (new_cap > max_size())
    throw std::length_error("vector::reserve");
  if (cp < new_cap)
    reallocate(new_cap); // except strong guarantee
}

template <typename T>
bool vector<T>::empty() const
{
  return sz == 0 ? true : false;
}

template <typename T>
typename vector<T>::size_type vector<T>::size() const
{
  return sz;
}

template <typename T>
void vector<T>::reallocate(size_t new_cap)
{
  reallocateImpl(new_cap, is_noexcept());
}


// TODO: should be called if move throw but T don't have copy ctr
template <typename T>
void vector<T>::reallocateImpl(size_t new_cap, std::true_type) // nothrow move
{
  // can throw don't modify original field
  void* raw = ::operator new(new_cap * sizeof(T)); // throw version
  T* temp_data = static_cast<T*>(raw);

  // Kalbs line

  // can't throw modify original field
  for(size_type idx = 0; idx < sz; ++idx)
    new (temp_data + idx) T(std::move(data[idx]));

  for (size_type idx = 0; idx < sz; ++idx)
    data[idx].~T();

  ::operator delete(data);
  std::swap(data, temp_data); // fundamental types (nothrow)
  std::swap(cp, new_cap); // fundamental types (nothrow)
}

template <typename T>
void vector<T>::reallocateImpl(size_t new_cap, std::true_type) // copy
{
  void* raw = ::operator new(new_cap * sizeof(T)); // throw version
  T* temp_data = static_cast<T*>(raw);

  size_type idx = 0;
  try {
    for(;idx < sz; ++idx)
      new (temp_data + idx) T(data[idx]);
  }
  catch (...) {
    for (size_type jdx = 0; jdx < idx; ++jdx)
      temp_data[jdx].~T();

    ::operator delete(temp_data);
    throw;
  }

  // Kalbs line

  for (int idx = 0; idx < sz; ++idx)
    data[idx].~T();

  ::operator delete(data);
  std::swap(data, temp_data);
  std::swap(cp, new_cap);
}