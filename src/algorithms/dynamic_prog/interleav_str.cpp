#include <vector>
#include <string>
#include <algorithm>
#include <gtest/gtest.h>

bool isInterleave(std::string& s1, std::string& s2, std::string& s3)
{
  std::vector<std::vector<int>> dp(s1.size() + 1, std::vector<int>(s2.size() + 1, 0));

  dp[0][0] = 1;

  for(int i = 1; i <= s2.size(); ++i)
    if (dp[0][i - 1] == 1 && s2[i - 1] == s3[i - 1])
      dp[0][i] = 1;

  for(int i = 1; i <= s1.size(); ++i)
    if (dp[i - 1][0] == 1 && s1[i - 1] == s3[i - 1])
      dp[i][0] = 1;

  for(int i = 1; i <= s1.size(); ++i)
  {
    for(int j = 1; j <= s2.size(); ++j)
    {
      if (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1] == 1)
        dp[i][j] = 1;
      if (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j] == 1)
        dp[i][j] = 1;
    }
  }

  return dp[s1.size()][s2.size()];
}

TEST(DynamicTest, Test1)
{
  std::string s1 = "axy";
  std::string s2 = "aab";
  std::string s3 = "aaxaby";
  EXPECT_EQ(isInterleave(s1, s2, s3), true);
}

TEST(DynamicTest, Test2)
{
  std::string s1 = "aabcc";
  std::string s2 = "dbbca";
  std::string s3 = "aadbbcbcac";
  EXPECT_EQ(isInterleave(s1, s2, s3), true);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}