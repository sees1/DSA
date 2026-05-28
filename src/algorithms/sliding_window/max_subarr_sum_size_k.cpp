#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

int maxSubarrSum(const std::vector<int>& arr, int k)
{
  if (arr.size() < k)
    return -1;

  int max_sum = 0;
  for(int i = 0; i < k; ++i)
    max_sum += arr[i];

  int win_sum = max_sum;
  for(int i = k; i < arr.size(); ++i)
  {
    win_sum += arr[i] - arr[i - k];
    max_sum = std::max(max_sum, win_sum);
  }

  return max_sum;
}

TEST(SlidingWindow, Test1)
{
  std::vector<int> arr = {100, 200, 300, 400};
  EXPECT_EQ(maxSubarrSum(arr, 2), 700);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}