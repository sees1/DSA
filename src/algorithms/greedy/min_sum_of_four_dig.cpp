#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

int minimumSum(int num) {
  std::string s;
  while(num != 0)
  {
    s.push_back('0' + num % 10);
    num /= 10;
  }

  std::sort(s.begin(), s.end());

  std::string f_num(1, s[0]);
  f_num += s[2];
  std::string s_num(1, s[1]);
  s_num += s[3];
  return std::stoi(f_num) + std::stoi(s_num);
}

TEST(DynamicTest, Test1)
{
  int num = 2932;
  EXPECT_EQ(minimumSum(num), 52);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}