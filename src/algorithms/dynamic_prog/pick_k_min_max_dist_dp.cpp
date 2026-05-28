#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

int helper(int idx, int prev_idx, int rem, 
           std::vector<int>& nums, int p, 
           std::vector<std::vector<std::vector<int>>>& dp)
{
  if (rem == p)
    return std::numeric_limits<int>::max();

  if (idx == nums.size())
    return -1;

  if (dp[idx][rem][prev_idx + 1] != -2)
    return dp[idx][rem][prev_idx + 1];

  int skip = helper(idx + 1, prev_idx, rem, nums, p, dp);

  int profit = (prev_idx == -1) ? std::numeric_limits<int>::max() : (nums[idx] - nums[prev_idx]);
  int next = helper(idx + 1, idx, rem + 1, nums, p, dp);
  int take = (next == -1) ? -1 : std::min(profit, next);

  return dp[idx][rem][prev_idx + 1] = std::max(skip, take);
}

int minmaxDist(std::vector<int>& nums, int p)
{
  std::sort(nums.begin(), nums.end());
  std::vector<std::vector<std::vector<int>>> dp(nums.size() + 1, std::vector<std::vector<int>>(p + 1, std::vector<int>(nums.size() + 1, -2)));

  return helper(0, -1, 0, nums, p, dp);
}

TEST(DynamicTest, Test1)
{
  std::vector<int> nums = {10, 1, 2, 7, 1, 3};
  EXPECT_EQ(minmaxDist(nums, 2), 1);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}