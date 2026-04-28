#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <gtest/gtest.h>

int helper(int idx, std::vector<int>& house, std::vector<int>& memo)
{
  if (idx < 0)
    return 0;
  else if (memo[idx] != -1)
    return memo[idx];

  int do_rob = house[idx] + helper(idx - 2, house, memo);
  int not_do_rob = helper(idx - 1, house, memo);

  memo[idx] = std::max(do_rob, not_do_rob);

  return memo[idx];
}

int rob(std::vector<int>& nums)
{
  std::vector<int> dp(nums.size(), -1);
  dp[0] = nums[0];
  return helper(nums.size() - 1, nums, dp);
}

TEST(DynamicTest, Test1)
{
  std::vector<int> nums = {1, 2, 3, 1};
  EXPECT_EQ(rob(nums), 4);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}