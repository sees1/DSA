#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

bool canPartition(std::vector<int>& nums)
{
  int total = std::accumulate(nums.begin(), nums.end(), 0);
  
  if (total % 2 != 0)
    return false;
  
  int target = total / 2;
  std::vector<int> dp(target + 1, 0);
  dp[0] = 1;

  for(auto& num : nums)
  {
    for(int i = target; i >= num; --i)
    {
      if (dp[i])
        continue;
      if (dp[i - num])
        dp[i] = 1;
      if (dp[target])
        return true;
    }
  }

  return false;
}

TEST(DynamicTest, Test1)
{
  std::vector<int> nums = {1, 2, 3, 4};
  EXPECT_EQ(canPartition(nums), 3);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}