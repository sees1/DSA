#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <gtest/gtest.h>

int lowerBound(std::vector<int>& arr, int target)
{
  int left = 0;
  int right = arr.size();

  while(left < right) // half open interval
  {
    int mid = (left + right) / 2;

    if (target <= arr[mid])
      right = mid;
    else
      left = mid + 1;
  }

  return left;
}

TEST(DynamicTest, Test1)
{
  std::vector<int> array {2, 3, 7, 10, 11, 11, 25};
  EXPECT_EQ(lowerBound(array, 9), 3);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}