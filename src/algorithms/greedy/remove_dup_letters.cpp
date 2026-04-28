#include <vector>
#include <string>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

std::string removeDuplicateLetters(std::string s) {
  std::unordered_map<char, int> last_occur;
  for(int i = 0; i < s.size(); ++i)
    last_occur[s[i]] = i;
    
  std::unordered_set<char> used_chars;
  std::stack<char> stac;

  for(int i = 0; i < s.size(); ++i)
  {
    // already used character. We find unique (distinct)
    if (used_chars.count(s[i]))
      continue;

    while(!stac.empty() && s[i] < stac.top() && i < last_occur[s[i]])
    {
      used_chars.erase(s[i]);
      stac.pop();
    }

    stac.push(s[i]);
    used_chars.insert(s[i]);
  }

  std::string res;
  while(!stac.empty())
  {
    res += stac.top();
    stac.pop();
  }

  return res;
}

TEST(DynamicTest, Test1)
{
  std::string s = "bcabc";
  EXPECT_EQ(removeDuplicateLetters(s), "abc");
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}