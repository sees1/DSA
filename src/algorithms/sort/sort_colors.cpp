#include <vector>
#include <string>
#include <stack>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

void countingSort(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
  std::vector<int> opp(*std::max_element(begin, end) + 1, 0);
  std::for_each(begin, end, [&opp](auto& el)
  {
    opp[el] += 1;
  });

  int counter = 0;
  std::vector<int>::iterator pos = begin;
  std::for_each(opp.begin(), opp.end(), [&counter, &pos](auto& el)
  {
    for(int j = 0; j < el; ++j)
    {
      *pos = counter;
      ++pos;
    }
    counter++;
  });
}

void sortColors(std::vector<int>& nums)
{
  countingSort(nums.begin(), nums.end());
}

TEST(DynamicTest, Test1)
{
  std::vector<int> nums = {2, 0, 2, 1, 1, 0};
  std::vector<int> res = {0, 0, 1, 1, 2, 2};
  sortColors(nums);
  EXPECT_EQ(nums, res);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}