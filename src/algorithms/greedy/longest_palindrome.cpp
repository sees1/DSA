#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <gtest/gtest.h>

int longestPalindrome(std::string s)
{
  std::unordered_map<char, int> freq_map;

  for(auto& c : s)
    ++freq_map[c];

  int odd = 0;
  int even = 0;
  for(auto& el : freq_map)
  {
    if (el.second % 2 == 0)
      even += el.second / 2;
    else
    {
      even += el.second / 2;
      ++odd;
    }
  }

  return even * 2 + (odd == 0 ? 0 : 1);
}

TEST(DynamicTest, Test1)
{
  std::string s = "abccccdd";
  EXPECT_EQ(longestPalindrome(s), 7);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}