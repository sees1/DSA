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
void vector<T>::reallocate(size_t new_cap)
{
  void* raw = ::operator new(new_cap * sizeof(T), std::nothrow);
  if (!raw)
    throw std::runtime_error("Can't allocate memory!");

  T* temp_data = static_cast<T*>(raw);

  for(int idx = 0; idx < sz; ++idx)
  {
    new (temp_data + idx) T(std::move(data[idx]));
    data[idx].~T();
  }

  ::operator delete(data);
  data = temp_data;
  cp = new_cap;
}