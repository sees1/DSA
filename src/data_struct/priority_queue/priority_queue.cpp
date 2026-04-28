#include "data_struct/priority_queue/priority_queue.hpp"

namespace study {

  priority_queue::priority_queue(const std::vector<int>& container)
  : impl_(container)
  {
    size_t n = impl_.size();

    for(int i = n / 2 - 1; i >= 0; ++i)
      heapify(n, i);
  }

  // peak operation
  int priority_queue::top() const
  {
    if (impl_.empty())
      throw std::runtime_error("heap is empty");

    return impl_[0];
  }

  // push and rebalance tree
  void priority_queue::push(int value)
  {
    impl_.push_back(value);
    
    // heapify (down -> up fix tree invariant)   
    int idx = impl_.size() - 1;

    while(idx > 0 && impl_[(idx - 1) / 2] < impl_[idx])
    {
      std::swap(impl_[idx], impl_[(idx - 1) / 2]);
      idx = (idx - 1) / 2;
    }
  }

  // delete max element (top element)
  void priority_queue::pop()
  {
    if (impl_.empty())
      throw std::runtime_error("heap is empty");

    // swap max and last (often min) and remove max (which now - last)
    std::swap(impl_[0], impl_[impl_.size() - 1]);
    impl_.pop_back();

    heapify(impl_.size(), 0);
  }

  bool priority_queue::empty()
  {
    return impl_.empty();
  }

  void priority_queue::heapify(size_t right_bound, int temp_root_idx)
  {
    int idx = temp_root_idx;

    // heapify (up -> down fix tree invariant). Iterative form, O(1) space - nice chouse
    while(true)
    {
      int left_idx = 2 * idx + 1;
      int right_idx = 2 * idx + 2;
      int largest_idx = idx;
      if (left_idx < right_bound && impl_[left_idx] > impl_[largest_idx])
        largest_idx = left_idx;
      if (right_idx < right_bound && impl_[right_idx] > impl_[largest_idx])
        largest_idx = right_idx;

      if (largest_idx != idx)
      {
        std::swap(impl_[largest_idx], impl_[idx]);
        idx = largest_idx;
      }
      else
        break;
    }
  }

} // namespace study

