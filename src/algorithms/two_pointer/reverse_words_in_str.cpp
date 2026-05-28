#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

std::string reverseWords(std::string s)
{
  int right = 0;
  int idx = 0;

  std::reverse(s.begin(), s.end());

  for(size_t left = 0; left < s.size(); ++left)
  {
    if (s[left] != ' ')
    {
      if (idx != 0)
        s[idx++] = ' ';

      right = left;

      while(right < s.size() && s[right] != ' ')
        s[idx++] = s[right++];

      std::reverse(s.begin() + idx - (right - left), s.begin() + idx);

      left = right;
    }
  }

  s.erase(s.begin() + idx, s.end());
  return s;
}

TEST(TwoPointer, Test1)
{
  std::string s = "  hello world  ";
  EXPECT_EQ(reverseWords(s), std::string("world hello"));
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}