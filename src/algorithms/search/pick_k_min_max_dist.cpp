#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

bool check(std::vector<int>& arr, int mid, int k)
{
  int count = 1;
  int last = arr[0];

  for(int i = 0; i < arr.size(); ++i)
  {
    if (arr[i] - last >= mid)
    {
      count++;
      last = arr[i];
    }

    if (count == k)
      return true;
  }

  return false;
}

int minmaxDist(std::vector<int>& arr, int k)
{
  std::sort(arr.begin(), arr.end());

  int left = 0;
  int right = arr.size() - 1;
  int res = 0;

  while(left <= right)
  {
    int mid = left + (right - left) / 2;

    if (check(arr, mid, k))
    {
      res = mid;
      left = mid + 1;
    }
    else
      right = mid - 1;
  }

  return res;
}

TEST(DynamicTest, Test1)
{
  std::vector<int> array {1, 4, 9, 0, 2, 13, 3};
  EXPECT_EQ(minmaxDist(array, 4), 4);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}