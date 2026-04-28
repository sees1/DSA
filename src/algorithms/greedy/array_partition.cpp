#include <vector>
#include <string>
#include <algorithm>
#include <gtest/gtest.h>

int arrayPairSum(std::vector<int>& nums)
{
  std::sort(nums.begin(), nums.end());
  
  int res = 0;
  for(int i = 0; i < nums.size(); i+=2)
    res += nums[i];

  return res;
}

TEST(DynamicTest, Test1)
{
  std::vector<int> nums = {1, 4, 3, 2};
  EXPECT_EQ(arrayPairSum(nums), 4);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}