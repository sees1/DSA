#include <vector>
#include <numeric>
#include <string>

int longestOnes(std::vector<int>& nums, int k)
{
  int zero = 0;

  size_t max_el = 0;
  size_t right_idx = 0;
  size_t left_idx = 0;
  size_t nums_s = nums.size();
  while (right_idx != nums_s)
  {
    if (nums[right_idx] == 0)
      ++zero;
  
    while (zero > k)
    {
      if (nums[left_idx] == 0)
        --zero;
      ++left_idx;
    }

    max_el = std::max(max_el, right_idx - left_idx + 1);

    ++right_idx;
  }

  return max_el;
}

int main() {
  std::vector<int> nums = {0, 0, 1, 1, 0, 0,1 , 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1,1 };
  int k = 3;
  auto res = longestOnes(nums, k);
}