#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <limits>
#include <gtest/gtest.h>

int wiggleMaxLength(std::vector<int>& nums)
{
  int size = nums.size();
  int peak = 1;
  int valley = 1;
  for (int i = 1; i < size; ++i)
  {
    if (nums[i] > nums[i - 1])
      peak = valley + 1;
    else if (nums[i] < nums[i - 1])
      valley = peak + 1;
  }

  return std::max(peak, valley);
}

TEST(DynamicTest, Test1)
{
  std::vector<int> nums = {1, 4, 7, 2, 5};
  EXPECT_EQ(wiggleMaxLength(nums), 4);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}