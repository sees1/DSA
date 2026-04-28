#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

int numberOfArithmeticSlices(std::vector<int>& nums)
{
  int nums_s = nums.size();
  int prev_diff = nums[1] - nums[0];
  int ind = 0;

  int res = 0;

  for(int i = 1; i < nums_s - 1; ++i)
  {
    int diff = nums[i + 1] - nums[i];
    if(prev_diff == diff)
    {
      ++ind;
    }
    else
    {
      prev_diff = diff;
      ind = 0;
    }

    res += ind;
  }

  return res;
}

TEST(DynamicTest, Test1)
{
  std::vector<int> nums = {1, 2, 3, 4};
  EXPECT_EQ(numberOfArithmeticSlices(nums), 3);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}