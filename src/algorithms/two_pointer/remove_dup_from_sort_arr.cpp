#include <vector>
#include <gtest/gtest.h>

int removeDuplicates(std::vector<int>& nums)
{
  if(nums.size() <= 1)
    return nums.size();
  
  int k = 1;
  
  for(int i = 1; i < nums.size(); i++)
  {
    if(nums[i] != nums[k - 1])
      nums[k++] = nums[i];
  }

  return k;
}

TEST(TwoPointer, Test1)
{
  std::vector<int> numbers = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  EXPECT_EQ(removeDuplicates(numbers), 5);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}