#pragma once
#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <exception>
#include <stdexcept>

namespace study {
  class priority_queue {
  public:
    priority_queue(const std::vector<int>& container);

    int top() const;      // peak operation
    void push(int value); // push and rebalance tree
    void pop();           // delete max element (top element)
    bool empty();

  private:
    void heapify(size_t right_bound, int temp_root_idx);

  private:
    std::vector<int> impl_;
  };
} // namespace study