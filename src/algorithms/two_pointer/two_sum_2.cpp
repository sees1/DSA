#include <vector>
#include <gtest/gtest.h>

std::vector<int> twoSum(std::vector<int>& numbers, int target)
{
  int left = 0;
  int right = numbers.size() - 1;

  std::vector<int> res;

  while(left <= right)
  {
    int sum = numbers[left] + numbers[right];

    if (target == sum)
    {
      res.push_back(left + 1);
      res.push_back(right + 1);
      return res;
    }
    if (sum > target)
      right--;
    else
      left++;
  }

  return res;
}

TEST(TwoPointer, Test1)
{
  std::vector<int> numbers = {2, 7, 11, 15};
  std::vector<int> res = {0, 1};
  EXPECT_EQ(twoSum(numbers, 9), res);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}