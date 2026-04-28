#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <gtest/gtest.h>

int searchInsertK(const std::vector<int>& arr, int k)
{
  int left = 0;
  int right = arr.size() - 1;
  
  while (left < right - 1)
  {
    int mid = (left + right) / 2;

    if (arr[mid] == k)
      return mid;

    if (k > arr[mid])
      left = mid;
    else
      right = mid;
  }

  return right;
}

TEST(DynamicTest, Test1)
{
  std::vector<int> array {1, 3, 5, 6};
  EXPECT_EQ(searchInsertK(array, 5), 2);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}