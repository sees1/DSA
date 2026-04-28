#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

int solvePaths(std::vector<std::vector<int>>& dp, int m, int n, int row, int col)
{
  if (row == m - 1 && col == n - 1)
    return 1;

  if (dp[row][col] != -1)
    return dp[row][col];

  int down_path = 0;
  int right_path = 0;

  // can move down?
  if (row + 1 < m)  
    down_path = solvePaths(dp, m, n, row + 1, col);

  if (col + 1 < n)
    right_path = solvePaths(dp, m, n, row, col + 1);

  return dp[row][col] = right_path + down_path;
}

int uniquePaths(int m, int n)
{
  std::vector<std::vector<int>> dp(m, std::vector<int>(n, -1));
  return solvePaths(dp, m, n, 0, 0);
}

TEST(DynamicTest, Test1)
{
  EXPECT_EQ(uniquePaths(3, 7), 28);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}