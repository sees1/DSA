#include <type_traits>
#include <cstdlib>
#include <cstring>
#include <stdexcept>

namespace study {

template <typename InputIter>
using RequiredInputIter = std::enable_if_t<std::is_base_of_v<std::input_iterator_tag, typename std::iterator_traits<InputIter>::iterator_category>>;

template <typename T>
class vector {
public:
  using size_type = size_t;
  using reference = T&;
  using const_reference = const T&;
  using pointer = T*;
  using const_pointer = const T*;

  using difference_type = std::ptrdiff_t

public:
  static constexpr bool is_noexcept() { return std::is_nothrow_move_constructible_v<T>; }

public:
  vector();
  vector(size_t count);
  vector(size_t count, const T& value);
  template <typename InputIter, typename = RequiredInputIter<InputIter>>
  vector(InputIter begin, InputIter end);

  // TODO: add here 4 more constructors
  ~vector();

  void push_back(const T& value);
  void push_back(T&& value);

  template <typename... Args>
  void emplace_back(Args&&... args);

  void clear();

  // element access
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;

  // capacity
  bool empty() const;
  size_type max_size() const;
  void reserve(size_t new_cap);
  size_type size() const;

private:
  void reallocate(size_t new_cap);
  void reallocateImpl(size_t new_cap, std::true_type);
  void reallocateImpl(size_t new_cap, std::false_type);

private:
  T* data;
  size_t sz;
  size_t cp;
};

template <typename InputIter, typename ValT = typename std::iterator_traits<InputIter>::value_type,
          typename = RequiredInputIter<InputIter>> 
vector(InputIter begin, InputIter end) -> vector<ValT>;


#include "vector_impl.hpp"

} // namespace study

#include <vector>