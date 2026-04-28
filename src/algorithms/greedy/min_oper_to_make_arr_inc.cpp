#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <limits>
#include <gtest/gtest.h>

int minOperations(std::vector<int>& nums)
{
  int res = 0;
  for(int i = 1; i < nums.size(); ++i)
  {
    while(nums[i] <= nums[i - 1])
    {
      int diff = nums[i - 1] - nums[i] + 1;
      res += diff;
      nums[i] += diff;
    }
  }

  return res;
}

TEST(DynamicTest, Test1)
{
  std::vector<int> nums = {1, 1, 1};
  EXPECT_EQ(minOperations(nums), 3);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}