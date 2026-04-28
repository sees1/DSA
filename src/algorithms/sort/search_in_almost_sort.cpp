#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <string>
#include <algorithm>
#include <gtest/gtest.h>

int findTarget(const std::vector<int>& arr, int target)
{
  int left = 0;
  int right = arr.size() - 1;

  while(left <= right)
  {
    int mid = left + (right - left) / 2;

    if (target == arr[mid])
      return mid;
    if (mid > left && target == arr[mid - 1])
      return mid - 1;
    if (mid < right && target == arr[mid + 1])
      return mid + 1;

    if (target < arr[mid])
      right = mid - 2;
    else
      left = mid + 2;
  }

  return -1;
}

TEST(DynamicTest, Test1)
{
  std::vector<int> nums = {10, 3, 40, 20, 50, 80, 70};
  EXPECT_EQ(findTarget(nums, 40), 2);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}