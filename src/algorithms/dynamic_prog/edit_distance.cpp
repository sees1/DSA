#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <gtest/gtest.h>

int minDistance(std::string& word1, std::string& word2)
{
  int row_c = word2.size() + 1;
  int col_c = word1.size() + 1;
  std::vector<std::vector<int>> dp(row_c, std::vector<int>(col_c, 0));

  for(int i = 1; i < row_c; ++i)
    dp[i][0] = i;
  
  for(int i = 1; i < col_c; ++i)
    dp[0][i] = i;

  for(int i = 1; i < row_c; ++i)
  {
    for(int j = 1; j < col_c; ++j)
    {
      if(word2[i - 1] == word1[j - 1])
        dp[i][j] = dp[i - 1][j - 1];
      else
        dp[i][j] = std::min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
    }
  }

  return dp[row_c - 1][col_c - 1];
}

TEST(DynamicTest, Test1)
{
  std::string word1 = "horse";
  std::string word2 = "ros";
  EXPECT_EQ(minDistance(word1, word2), 3);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}