#include <vector>
#include <string>
#include <algorithm>
#include <gtest/gtest.h>

int maximum69Number(int num) {
  std::string s;
  while(num != 0)
  {
    s.push_back('0' + num % 10);
    num /= 10;
  }

  s[s.rfind('6')] = '9';

  int rank = 1;
  int res = 0;
  std::for_each(s.begin(), s.end(), [&rank, &res](auto& c)
  {
    res += rank * (c - '0');
    rank *= 10;
  });

  return res;
}

TEST(DynamicTest, Test1)
{
  int num = 9669;
  EXPECT_EQ(maximum69Number(num), 9969);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}