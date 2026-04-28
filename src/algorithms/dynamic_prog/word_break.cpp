#include <vector>
#include <string>
#include <gtest/gtest.h>

bool wordBreak(std::string& s, std::vector<std::string>& word_dict)
{
  std::vector<int> dp(s.size() + 1, 0);
  dp[0] = 1;

  for(int i = 1; i <= s.size(); ++i)
  {
    for(auto& word : word_dict)
    {
      int start = i - word.size();
      if (start >= 0 && dp[start] && s.substr(start, word.size()) == word)
      {
        dp[i] = 1;
        break;
      }
    }
  }

  return dp[s.size()];
}

TEST(DynamicTest, Test1)
{
  std::string s = "leetcode";
  std::vector<std::string> dic = {"leet", "code"};
  EXPECT_EQ(wordBreak(s, dic), true);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}