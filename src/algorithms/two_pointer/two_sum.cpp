#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <gtest/gtest.h>

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
  std::vector<std::pair<int, int>> n_with_idx;

  for(size_t idx = 0; idx < nums.size(); ++idx)
    n_with_idx.push_back({nums[idx], idx});

  std::sort(n_with_idx.begin(), n_with_idx.end());

  int left = 0;
  int right = nums.size() - 1;

  while(left < right)
  {
    int sum = n_with_idx[left].first + n_with_idx[right].first;
    if(sum == target)
      return {n_with_idx[left].second, n_with_idx[right].second};
    else if (sum > target)
      right--;
    else
      left++;
  }

  return {-1, -1};
}

TEST(TwoPointer, Test1)
{
  std::vector<int> nums = {3, 2, 4};
  std::vector<int> res = {1, 2};
  EXPECT_EQ(twoSum(nums, 6), res);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}