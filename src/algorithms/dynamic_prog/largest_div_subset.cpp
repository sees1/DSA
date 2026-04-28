#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <limits>
#include <gtest/gtest.h>

std::vector<int> largestDivisibleSubset(std::vector<int>& nums)
{
  std::sort(nums.begin(), nums.end());
  int nums_s = nums.size();

  std::vector<int> sz(nums_s, 1);
  std::vector<int> prev_pos(nums_s, -1);
  int max_i = 0;

  for(int i = 1; i < nums_s; ++i)
  {
    for(int j = 0; j < i; ++j)
    {
      if (nums[i] % nums[j] == 0 && sz[i] < sz[j] + 1)
      {
        sz[i] = sz[j] + 1;
        prev_pos[i] = j;
      }
    }
    if (sz[i] > sz[max_i]) max_i = i;    
  }

  std::vector<int> res;
  for(int i = max_i; i >= 0; i = prev_pos[i])
    res.push_back(nums[i]);

  return res;
}

TEST(DynamicTest, Test1)
{
  std::vector<int> nums = {1, 2, 4, 8};
  std::vector<int> res(nums.rbegin(), nums.rend());
  EXPECT_EQ(largestDivisibleSubset(nums), res);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}