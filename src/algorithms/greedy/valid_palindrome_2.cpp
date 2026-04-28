#include <vector>
#include <string>
#include <algorithm>
#include <gtest/gtest.h>

bool checkValid(std::string s, int left, int right)
{
  while(left < right)
  {
    if (s[left] == s[right])
    {
      left++;
      right--;
    }
    else
      return false;
  }

  return true;
}

bool validPalindrome(std::string s)
{
  int left = 0;
  int right = s.size() - 1;

  while (left < right)
  {
    if (s[left] == s[right])
    {
      ++left;
      --right;
    }
    else
      return checkValid(s, left + 1, right) || checkValid(s, left, right - 1);
  }

  return true;
}

TEST(DynamicTest, Test1)
{
  std::string s = "yd";
  EXPECT_EQ(validPalindrome(s), true);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}