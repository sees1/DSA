#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <limits>
#include <gtest/gtest.h>

void wiggleSort(std::vector<int>& nums)
{
  size_t nums_s = nums.size();

  std::sort(nums.begin(), nums.end());
  
  auto mid = nums.begin() + (nums_s + 1) / 2;
  
  std::vector<int> first_half(nums.begin(), mid);
  std::vector<int> second_half(mid, nums.end());
  
  nums.clear();
  
  for(int i = 0; i < nums_s; ++i)
  {
    if (i % 2 == 0)
    {
      nums.push_back(first_half.back());
      first_half.pop_back();
    }
    else
    {
      nums.push_back(second_half.back());
      second_half.pop_back();
    }
  }   
}

TEST(DynamicTest, Test1)
{
  std::vector<int> nums = {1,4,3,4,1,2,1,3,1,3,2,3,3};
  std::vector<int> func_res = {3,4,2,4,2,3,1,3,1,3,1,3,1};
  wiggleSort(nums);
  EXPECT_EQ(nums, func_res);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}