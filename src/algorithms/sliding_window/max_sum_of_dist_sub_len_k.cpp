#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <map>
#include <algorithm>
#include <gtest/gtest.h>

int maximumSubarraySum(std::vector<int>& nums, int k)
{
  if (nums.size() < k)
    return 0;

  std::unordered_map<int, int> fm;
  int max_sum = 0;
  int sum = 0;
  for(int i = 0; i < k; ++i)
  {
    fm[nums[i]]++;
    sum += nums[i];
  }

  if (fm.size() >= k)
    max_sum = sum;

  for(int i = k; i < nums.size(); ++i)
  {
    fm[nums[i]]++;
    fm[nums[i - k]]--;

    sum += nums[i] - nums[i - k];

    if (fm[nums[i - k]] == 0)
      fm.erase(nums[i - k]);

    if (fm.size() >= k)
      max_sum = std::max(max_sum, sum);
  }

  return max_sum;
}

TEST(SlidingWindow, Test1)
{
  std::vector<int> arr = {1, 5, 4, 2, 9, 9, 9};
  EXPECT_EQ(maximumSubarraySum(arr, 3), 15);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}