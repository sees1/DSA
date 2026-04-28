#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

int upper_bound(std::vector<int>& array, int target)
{
  int left = 0;
  int right = array.size();

  while(left < right)
  {
    int mid = left + (left - right) / 2;

    if (target < array[mid])
      right = mid;
    else 
      left = mid + 1;
  }

  return left;
}

TEST(DynamicTest, Test1)
{
  std::vector<int> array {2, 3, 7, 10, 11, 11, 25};
  EXPECT_EQ(upper_bound(array, 9), 3);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}