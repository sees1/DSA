#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

std::string removeDigit(std::string number, char digit) {
  int max = std::numeric_limits<int>::min();
  std::string res;
  for(int i = 0; i < number.size(); ++i)
  {
    if (number[i] == digit)
    {
      std::string temp = number;
      temp.erase(i, 1);
      if (max < std::stoi(temp))
      {
        max = std::stoi(temp);
        res = temp;
      }
    }
  }

  return res;
}

TEST(DynamicTest, Test1)
{
  std::string number = "1231";
  char digit = '1';
  EXPECT_EQ(removeDigit(number, digit), "231");
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}