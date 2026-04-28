#include <cstdlib>
#include <cstring>
#include <stdexcept>

namespace study {

template <typename T>
class vector {
public:
  using size_type = size_t;
  using reference = T&;
  using const_reference = const T&;
  using pointer = T*;
  using const_pointer = const T*;

public:
  vector();
  vector(size_t count);
  vector(size_t count, const T& value);
  ~vector();

  bool empty() const;
  size_type size() const;

  void push_back(const T& value);
  void push_back(T&& value);

  void clear();

  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;

private:
  void reallocate(size_t new_cap);

private:
  T* data;
  size_t sz;
  size_t cp;
};

#include "data_struct/vector/vector_impl.hpp"

} // namespace study