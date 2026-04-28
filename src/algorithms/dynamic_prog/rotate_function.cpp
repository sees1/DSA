#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

int maxRotateFunction(std::vector<int>& nums)
{
  int sz = nums.size();
  int sum = 0;
  int prev = 0;
  for(int i = 0; i < sz; ++i)
  {
    sum += nums[i];
    prev += i * nums[i];
  }

  int max = prev;

  for(int i = 1; i < sz; ++i)
  {
    prev = prev + sum - sz * nums[sz - i];
    
    max = std::max(max, prev);
  }

  return max;
}

TEST(DynamicTest, Test1)
{
  std::vector<int> nums = {4, 3, 2, 6};
  EXPECT_EQ(maxRotateFunction(nums), 26);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}