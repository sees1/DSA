#include <string>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

void helper(std::vector<std::vector<int>>& dp,
            std::vector<std::vector<std::string>>& res,
            std::vector<std::string>& path,
            std::string& s,
            int pos)
{
  if (pos >= s.size())
  {
    res.push_back(path);
    return;
  }

  for (int end = pos; end < s.size(); ++end)
  {
    if (dp[pos][end])
    {
      path.push_back(s.substr(pos, end - pos + 1));
      helper(dp, res, path, s, end + 1);
      path.pop_back();
    }
  }
}

std::vector<std::vector<std::string>> partition(std::string s) {
  size_t s_size = s.size();
  std::vector<std::vector<int>> dp(s_size, std::vector<int>(s_size, 0));

  for (int i = 0; i < s_size; ++i)
    dp[i][i] = 1;

  for (int len = 2; len <= s_size; ++len)
  {
    for (int i = 0; i <= s_size - len; ++i)
    {
      int j = i + len - 1;
      
      if (s[i] == s[j] && (len == 2 || dp[i + 1][j - 1]))
        dp[i][j] = 1;
    }
  }

  std::vector<std::vector<std::string>> res;
  std::vector<std::string> path;
  helper(dp, res, path, s, 0);
  return res;
}

TEST(DynamicTest, Test1)
{
  std::string s = "aab";
  std::vector<std::vector<std::string>> res = {{"a", "a", "b"}, {"aa", "b"}};
  EXPECT_EQ(partition(s), res);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}