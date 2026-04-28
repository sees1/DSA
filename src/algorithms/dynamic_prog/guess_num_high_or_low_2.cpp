#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <gtest/gtest.h>

int helper(std::vector<std::vector<int>>& dp, int start, int end)
{
  if (start >= end)
    return 0;

  if (dp[start][end] != -1)
    return dp[start][end];

  int res = std::numeric_limits<int>::max();

  for(int piv = start; piv <= end; ++piv)
  {
    int temp = piv + std::max(helper(dp, start, piv - 1), helper(dp, piv + 1, end));
    res = std::min(res, temp);
  }

  return dp[start][end] = res;
}

int getMoneyAmount(int n)
{
  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, -1));
  return helper(dp, 1, n);
}

TEST(DynamicTest, Test1)
{
  int n = 10;
  EXPECT_EQ(getMoneyAmount(n), 16);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}