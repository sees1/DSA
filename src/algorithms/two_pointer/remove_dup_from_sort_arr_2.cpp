#include <vector>
#include <gtest/gtest.h>

int removeDuplicates(std::vector<int>& nums)
{
  if(nums.size() <= 2)
    return nums.size();
  
  int k = 2;
  for(int i = 2; i < nums.size(); i++)
  {
    if(nums[i] != nums[k - 2])
      nums[k++] = nums[i];
  }

  return k;
}

TEST(TwoPointer, Test1)
{
  std::vector<int> numbers = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  EXPECT_EQ(removeDuplicates(numbers), 8);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}