#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <gtest/gtest.h>

int floorSqrt(int x)
{
  int left = 0;
  int right = x;
  int res = 0;

  while(left <= right)
  {
    int mid = left + (right - left) / 2;

    if (mid * mid == x)
      return mid;

    if (x < mid * mid )
      right = mid - 1;
    else 
    {
      left = mid + 1;
      res = mid;
    }
  }

  return res;
}

TEST(SearchTest, Test1)
{
  int x = 11;
  EXPECT_EQ(floorSqrt(x), 3);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}