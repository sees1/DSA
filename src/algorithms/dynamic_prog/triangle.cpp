#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <gtest/gtest.h>

int solveMinimum(std::vector<std::vector<int>>& dp, std::vector<std::vector<int>>& triangle, int row, int col)
{
  if (dp[row][col] != -1)
    return dp[row][col];

  if (row < triangle.size() - 1 && col <= triangle[row].size() - 1)
    return dp[row][col] = triangle[row][col] + std::min(solveMinimum(dp, triangle, row + 1, col), solveMinimum(dp, triangle, row + 1, col + 1));
  else
    return dp[row][col] = triangle[row][col];
}

int minimumTotal(std::vector<std::vector<int>>& triangle)
{
  std::vector<std::vector<int>> dp(triangle.size(), std::vector<int>(triangle.size(), -1));
  return solveMinimum(dp, triangle, 0, 0);
}

TEST(DynamicTest, Test1)
{
  std::vector<std::vector<int>> triangle = 
  {{2},
   {3, 4},
   {6, 5, 7},
   {4, 1, 8, 3}};
  EXPECT_EQ(minimumTotal(triangle), 11);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}