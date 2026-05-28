#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

void nextPermutation(std::vector<int>& nums) {
  int right = nums.size() - 2;

  while(right >= 0 && nums[right] >= nums[right + 1])
    right--;

  if (right >= 0) 
  {
    for(int idx = nums.size() - 1; idx > right; --idx)
    {
      if (nums[right] < nums[idx])
        std::swap(nums[right], nums[idx]);
    }
  }

  std::reverse(nums.begin() + right + 1, nums.end());
}

TEST(TwoPointer, Test1)
{
  std::vector<int> arr = {1, 3, 2};
  nextPermutation(arr);
  std::vector<int> res = {2, 1, 3};
  EXPECT_EQ(arr, res);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}