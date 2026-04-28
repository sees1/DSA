#include <vector>
#include <numeric>
#include <string>
#include <algorithm>
#include <limits>
#include <gtest/gtest.h>

void helper(int n, int& res)
{
  while(n != 1)
  {
    if (n % 2 == 0)
    {
      n /= 2;
      ++res;
    }
  }
}

int integerReplacement(int n)
{
  int res = 0;

  while(n != 1)
  {
    if (n % 2 == 0)
      n /= 2;
    else if (n == 3 || !((n >> 1) & 1))
      --n;
    else
      ++n;

    ++res;
  }

  return res;
}

TEST(DynamicTest, Test1)
{
  int n = 7;
  EXPECT_EQ(integerReplacement(n), 3);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}