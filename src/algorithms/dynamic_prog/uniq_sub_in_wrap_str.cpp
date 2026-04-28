#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

bool isNext(char a, char b)
{
  return a == 'z' ? b == 'a' : a + 1 == b;
}

int findSubstringInWraproundString(std::string& s)
{
  std::unordered_map<char, int> max_lengths;

  int max = 1;
  for(size_t i = 0; i < s.size(); ++i)
  {
    if (max_lengths.find(s[i]) == max_lengths.end())
      max_lengths[s[i]] = max;
    else
      max_lengths[s[i]] = std::max(max, max_lengths[s[i]]);

    if (i + 1 < s.size() && isNext(s[i], s[i + 1]))
      ++max;
    else
      max = 1;
  }

  int res = 0;
  for(auto& pair : max_lengths)
    res += pair.second;

  return res;
}

TEST(DynamicTest, Test1)
{
  std::string s = "cac";
  EXPECT_EQ(findSubstringInWraproundString(s), 6);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}