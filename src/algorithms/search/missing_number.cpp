#include <vector>
#include <numeric>
#include <limits>
#include <algorithm>
#include <cstdlib>
#include <gtest/gtest.h>

struct cleaner_tag;

template <typename T = void>
int missingNumber(std::vector<int>& arr)
{
  int left = 0;
  int right = arr.size() - 1;
  while(left < right)
  {
    int mid = left + (right - left) / 2;

    if (arr[left] - left != arr[mid] - mid)
      right = mid - 1;
    else if (arr[mid] - mid != arr[right] - right)
      left = mid + 1;
  }

  return left + 1;
}


// via lower_bound
template <>
int missingNumber<cleaner_tag>(std::vector<int>& arr)
{
  int left = 0;
  int right = arr.size();
  while(left < right)
  {
    int mid = left + (right - left) / 2;

    if (arr[mid] > mid + 1)
      right = mid;
    else
      left = mid + 1;
  }

  return left + 1;
}

TEST(DynamicTest, Test1)
{
  std::vector<int> array {2, 3, 7, 10, 11, 11, 25};
  EXPECT_EQ(missingNumber(array), 3);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}