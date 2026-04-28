#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <gtest/gtest.h>

int maximalSquare(std::vector<std::vector<char>>& matrix)
{
  int m = matrix.size();
  int n = matrix[0].size();
  std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

  int res = 0;

  for(int row = 0; row < matrix.size(); ++row)
  {
    for(int col = 0; col < matrix[0].size(); ++col)
    {
      if(matrix[row][col] == '1')
      {
        dp[row + 1][col + 1] = std::min({dp[row][col], dp[row + 1][col], dp[row][col + 1]}) + 1;
        res = std::max(res, dp[row + 1][col + 1]);
      }
    }
  }

  return res * res;
}

TEST(DynamicTest, Test1)
{
  std::vector<std::vector<char>> matrix =
  {{'1', '0', '1', '0', '0'},
   {'1', '0', '1', '1', '1'},
   {'1', '1', '1', '1', '1'},
   {'1', '0', '0', '1', '0'}};
  EXPECT_EQ(maximalSquare(matrix), 4);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}