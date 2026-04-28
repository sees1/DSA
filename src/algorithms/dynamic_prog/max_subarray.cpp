#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <gtest/gtest.h>

struct kadane_tag {};
struct dynamic_bu_tag {};
struct dynamic_ub_tag {};

template <typename Tag>
int maxSubArray(std::vector<int>& nums) { return 0; }

template <>
int maxSubArray<kadane_tag>(std::vector<int>& nums)
{
  int result = std::numeric_limits<int>::min();
  int maxSum = 0;

  for(auto& num : nums)
  {
    maxSum = std::max(num, maxSum + num);
    result = std::max(result, maxSum);
  }

  return result;
}

int solve(std::vector<int>& nums, std::vector<std::vector<int>>& dp, int pos, bool pick)
{
  if (pos >= nums.size())
    return pick ? 0 : -1e5;

  if (dp[pick][pos] != -1)
    return dp[pick][pos];

  if (pick)
    return dp[pick][pos] = std::max(0, nums[pos] + solve(nums, dp, pos + 1, true));
  else
    return dp[pick][pos] = std::max(solve(nums, dp, pos + 1, false), nums[pos] + solve(nums, dp, pos + 1, true));
}

template <>
int maxSubArray<dynamic_ub_tag>(std::vector<int>& nums)
{
  std::vector<std::vector<int>> dp(2, std::vector<int>(nums.size(), -1));
  return solve(nums, dp, 0, false);
}

template <>
int maxSubArray<dynamic_bu_tag>(std::vector<int>& nums)
{
  std::vector<std::vector<int>> dp(2, std::vector<int>(nums.size()));
  dp[0][0] = dp[1][0] = nums[0];

  for(int i = 1; i < nums.size(); ++i)
  {
    dp[1][i] = std::max(nums[i], nums[i] + dp[1][i - 1]);
    dp[0][i] = std::max(dp[1][i], dp[0][i - 1]);
  }

  return dp[0].back();
}

TEST(KadaneTest, Test1)
{
  std::vector<int> nums = {-2, 1, -3, 4, -1 , 2, 1, -5, 4};
  EXPECT_EQ(maxSubArray<kadane_tag>(nums), 6);
}

TEST(DynamicTest, BottomUpApproach)
{
  std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  EXPECT_EQ(maxSubArray<dynamic_bu_tag>(nums), 6);
}

TEST(DynamicTest, UpBottomApproach)
{
  std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  EXPECT_EQ(maxSubArray<dynamic_ub_tag>(nums), 6);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}