#include <vector>
#include <string>
#include <algorithm>
#include <gtest/gtest.h>

int solveTrees(std::vector<int>& dp, int n)
{
  if (n <= 1)
    return 1;

  if (dp[n] != -1)
    return dp[n];

  int uniq_bst = 0;

  for(int i = 1; i <= n; ++i)
    uniq_bst += solveTrees(dp, i - 1) * solveTrees(dp, n - i);

  return dp[n] = uniq_bst;
}

int numTrees(int n)
{
  std::vector<int> dp(n + 1, -1);
  return solveTrees(dp, n);
}

TEST(DynamicTest, Test1)
{
  int n = 3;
  EXPECT_EQ(numTrees(n), 5);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}