#include <vector>
#include <string>
#include <algorithm>
#include <gtest/gtest.h>

int dfs(std::vector<std::pair<int, int>>& dp, std::vector<int>& prices, int pos, bool buying)
{
  if (pos > prices.size() - 1)
    return 0;

  if (dp[pos].first != -1 && buying == 0)
    return dp[pos].first;
  else if (dp[pos].second != -1 && buying == 1)
    return dp[pos].second;

  int cooldown = dfs(dp, prices, pos + 1, buying);
  if (buying)
  {
    int buy = dfs(dp, prices, pos + 1, !buying) - prices[pos];
    dp[pos].second = std::max(buy, cooldown);
  }
  else
  {
    int sell = dfs(dp, prices, pos + 2, !buying) + prices[pos];
    dp[pos].first = std::max(sell, cooldown);
  }

  if (buying == 0)
    return dp[pos].first;
  else
    return dp[pos].second;
}

int maxProfit(std::vector<int>& prices)
{
  std::vector<std::pair<int, int>> dp(prices.size(), {-1, -1});
  return dfs(dp, prices, 0, true);
} 

TEST(DynamicTest, Test1)
{
  std::vector<int> prices = {1, 2, 3, 0, 2};
  EXPECT_EQ(maxProfit(prices), 3);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}