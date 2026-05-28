#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <gtest/gtest.h>

int minSubArrayLen(int target, std::vector<int>& nums)
{
  int sum = 0;
  int left = 0;
  int right = 0;
  int ans = std::numeric_limits<int>::max();

  while(right < nums.size())
  {
    while(right < nums.size() && sum < target)
    {
      sum += nums[right++];
    }
    if (right == nums.size() && sum < target) // count all values from massive but whatever less or equat than target
      break;

    while(left < right && sum - nums[left] >= target)
    {
      sum -= nums[left++];
    }

    ans = std::min(ans, right - left);

    //shift
    sum -= nums[left++];
  }

  return ans == std::numeric_limits<int>::max() ? 0 : ans;
}

TEST(TwoPointer, Test1)
{
  std::vector<int> nums = {2, 3, 1, 2, 4, 3};
  EXPECT_EQ(minSubArrayLen(7, nums), 2);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}