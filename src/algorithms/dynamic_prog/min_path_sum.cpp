#include <vector>
#include <algorithm>
#include <limits>
#include <gtest/gtest.h>

int solveSum(std::vector<std::vector<int>>& dp, std::vector<std::vector<int>>& grid, int row, int col)
{
  if (row == grid.size() - 1 && col == grid[0].size() - 1)
    return grid[row][col];

  if (dp[row][col] != -1)
    return dp[row][col];

  int min_down = std::numeric_limits<int>::max();
  int min_right = std::numeric_limits<int>::max();

  if (row + 1 < grid.size())
    min_down = solveSum(dp, grid, row + 1, col);

  if (col + 1 < grid[0].size())
    min_right = solveSum(dp, grid, row, col + 1);

  return dp[row][col] = grid[row][col] + std::min(min_down, min_right);
}

int minPathSum(std::vector<std::vector<int>>& grid)
{
  std::vector<std::vector<int>> dp(grid.size(), std::vector<int>(grid[0].size(), -1));
  return solveSum(dp, grid, 0, 0);
}

TEST(DynamicTest, Test1)
{
  std::vector<std::vector<int>> grid =
  {{1, 3, 1},
   {1, 5, 1},
   {4, 2, 1}};
  EXPECT_EQ(minPathSum(grid), 7);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}