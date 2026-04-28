#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

int solvePaths(std::vector<std::vector<int>>& dp, std::vector<std::vector<int>>& obstacle, int m, int n, int row, int col)
{
  if (row == 0 && col == 0 && obstacle[row][col])
    return 0; 

  if (row == m - 1 && col == n - 1)
    return obstacle[row][col] ? 0 : 1;

  if (dp[row][col] != -1)
    return dp[row][col];

  int down_path = 0;
  int right_path = 0;

  // can move down?
  if (row + 1 < m && !obstacle[row + 1][col])  
    down_path = solvePaths(dp, obstacle, m, n, row + 1, col);

  if (col + 1 < n && !obstacle[row][col + 1])
    right_path = solvePaths(dp, obstacle, m, n, row, col + 1);

  return dp[row][col] = right_path + down_path;
}

int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacle_grid)
{
  int m = obstacle_grid.size();
  int n = obstacle_grid[0].size();
  std::vector<std::vector<int>> dp(m, std::vector<int>(n, -1));
  return solvePaths(dp, obstacle_grid, m, n, 0, 0);
}

TEST(DynamicTest, Test1)
{
  std::vector<std::vector<int>> obstacle_grid =
  {{0, 0, 0},
   {0, 1, 0},
   {0, 0, 0}};
  EXPECT_EQ(uniquePathsWithObstacles(obstacle_grid), 2);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}