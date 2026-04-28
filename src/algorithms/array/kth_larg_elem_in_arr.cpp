#include <queue>
#include <vector>

int findKthLargest(std::vector<int>& nums, int k) {
  std::priority_queue<int, std::vector<int>, std::greater<int>> heap;

  for(int num : nums)
  {
    heap.push(num);
    if (heap.size() > k)
      heap.pop();
  }

  return heap.top();
}

int main() {
  std::vector<int> nums = {3, 2, 1, 5, 6, 4};
  int k = 2;
  auto res = findKthLargest(nums, k);
}