#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

int helper(std::vector<int>& dp, std::vector<int>& nums, int remain)
{
  if(remain == 0)
    return 1;
  else if (remain < 0)
    return 0;
  
  if(dp[remain] != -1)
    return dp[remain];

  int res = 0;

  for(auto& i : nums)
  {
    res += helper(dp, nums, remain - i);
  }

  return dp[remain] = res;
}

int combinationSum4(std::vector<int>& nums, int target)
{
  std::vector<int> dp(target + 1, -1);
  return helper(dp, nums, target);
}

TEST(DynamicTest, Test1)
{
  std::vector<int> nums = {1, 2, 3};
  EXPECT_EQ(combinationSum4(nums, 4), 7);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}