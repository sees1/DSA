#include <vector>
#include <algorithm>
#include <iostream>

int singleNumber(std::vector<int>& nums)
{
  std::sort(nums.begin(), nums.end());

  size_t iter = 1;
  while(iter < nums.size())
  {
      if (nums[iter] != nums[iter - 1])
          return nums[iter - 1];

      iter += 2;
  }

  return nums[iter - 1];
}

int main() {
  std::vector<int> nums = {4, 1, 2, 1, 2};
  auto res = singleNumber(nums);
}