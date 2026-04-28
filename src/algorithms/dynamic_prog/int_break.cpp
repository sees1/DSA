#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <limits>
#include <gtest/gtest.h>

int helper(int n, std::vector<int>& dp)
{
  if (n == 1)
    return 1;
  
  if (dp[n] != -1)
    return dp[n];

  int res = 0;

  for(int i = 1; i < n; ++i)
    res = std::max(res, std::max(i * (n - i),             // case
                                 i * (helper(n - i, dp)))); // opposite case

  return dp[n] = res;
}

int integerBreak(int n)
{
  std::vector<int> dp(n + 1, -1);
  return helper(n, dp);
}

TEST(DynamicTest, Test1)
{
  int n = 10;
  EXPECT_EQ(integerBreak(n), 36);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}