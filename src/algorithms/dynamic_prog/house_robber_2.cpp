#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <gtest/gtest.h>

int helper(int idx, std::vector<int>& house, std::vector<int>& memo)
{
  if (idx < 0 )
    return 0;
  else if (memo[idx] != -1)
    return memo[idx];

  int do_rob = house[idx] + helper(idx - 2, house, memo);
  int not_do_rob = helper(idx - 1, house, memo);

  return memo[idx] = std::max(do_rob, not_do_rob);
}

int rob(std::vector<int>& nums)
{
  if (nums.size() == 1) 
    return nums[0];
  std::vector<int> dp1(nums.size() - 1, -1);
  dp1[0] = nums[0];
  std::vector<int> dp2(nums.size() - 1, -1);
  dp2[0] = nums[1];
  std::vector<int> nums2 = nums;
  nums.pop_back();
  nums2.erase(nums2.begin());
  return std::max(helper(nums.size() - 1, nums, dp1),
                  helper(nums2.size() - 1, nums2, dp2));
}

TEST(DynamicTest, Test1)
{
  std::vector<int> nums = {0};
  EXPECT_EQ(rob(nums), 0);
}

TEST(DynamicTest, Test2)
{
  std::vector<int> nums = {200, 3, 140, 20, 10};
  EXPECT_EQ(rob(nums), 340);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}