#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <gtest/gtest.h>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
{
  std::sort(nums.begin(), nums.end());

  std::vector<std::vector<int>> res;

  for(int i = 0; i < nums.size(); ++i)
  {
    if (i > 0 && nums[i] == nums[i - 1]) // optimization
      continue;
      
    int search = nums[i];

    int left = i + 1;
    int right = nums.size() - 1;

    while(left < right)
    {
      int total = search + nums[left] + nums[right];

      if (total > 0)
        --right;
      else if (total < 0)
        ++left;
      else
      {
        res.push_back({search, nums[right], nums[left]});
        ++left;

        while(nums[left] == nums[left - 1] && left < right) // remove dup
          ++left;
      }
    }
  }

  return res;
}

TEST(TwoPointer, Test1)
{
  std::vector<int> numbers = {-1, 0, 1, 2, -1, -4};
  std::vector<std::vector<int>> res = {{-1, -1, 2}, {-1, 0, 1}};
  EXPECT_EQ(threeSum(numbers), res);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}