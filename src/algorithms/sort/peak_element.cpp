#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

int peakElement(const std::vector<int>& arr)
{
  int left = 0;
  int right = arr.size() - 1;

  if (arr.size() == 1)
    return 0;

  if (arr[0] > arr[1])
    return 0;
  
  if (arr[arr.size() - 2] < arr[arr.size() - 1])
    return arr.size() - 1;

  while(left <= right)
  {
    int mid = left + (right - mid) / 2;

    if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
      return mid;

    if (arr[mid] < arr[mid + 1])
      left = mid + 1;
    else
      right = mid - 1;
  }

  return -1;
}

TEST(DynamicTest, Test1)
{
  std::vector<int> nums = {1, 2, 4, 5, 7, 8, 3};
  EXPECT_EQ(peakElement(nums), 5);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}