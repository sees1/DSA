#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <gtest/gtest.h>

int solveDecode(std::vector<int>& dp, std::string& s, int pos)
{
  if (pos > s.size() - 1)
    return 1;

  if (s[pos] == '0')
    return 0;

  if (dp[pos] != -1)
    return dp[pos];

  int by_one = solveDecode(dp, s, pos + 1);
  int by_two = 0;

  if (pos + 1 < s.size() &&
     (s[pos] == '1' || (s[pos] == '2' && (s[pos + 1] >= '1' && s[pos + 1] <= '6'))))
  {
    by_two = solveDecode(dp, s, pos + 2);
  }

  return dp[pos] = by_one + by_two;
}

// memoization (dfs + memoization)
int numDecodings(std::string& s)
{
  std::vector<int> dp(s.size(), -1);
  return solveDecode(dp, s, 0);
}

TEST(DynamicTest, Test1)
{
  std::string s = "2263";
  EXPECT_EQ(numDecodings(s), 3);
}

TEST(DynamicTest, Test2)
{
  std::string s = "1201234";
  EXPECT_EQ(numDecodings(s), 3);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}