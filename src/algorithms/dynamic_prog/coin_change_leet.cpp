#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <numeric>
#include <gtest/gtest.h>

int solve(std::vector<int>& dp, const std::vector<int>& coins, int rem) {
  if (rem < 0)
    return -1; // Invalid state
  else if (rem == 0)
    return 0;  // Base case: amount is 0
  else if (dp[rem] != -2)
    return dp[rem]; // Return cached result
  
  int min_count = std::numeric_limits<int>::max();
  
  for (int coin : coins) {
    int res = solve(dp, coins, rem - coin);
    if (res >= 0 && res < min_count)
      min_count = 1 + res;
  }
  
  // Cache the result before returning
  dp[rem] = (min_count == std::numeric_limits<int>::max()) ? -1 : min_count;
  return dp[rem];
}

int coinChange(const std::vector<int>& coins, int sum)
{
  std::vector<int> dp(sum + 1, -2);
  return solve(dp, coins, sum);
}

TEST(DynamicTest, Test1)
{
  std::vector<int> prices = {1, 2, 5};
  EXPECT_EQ(coinChange(prices, 11), 3);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}