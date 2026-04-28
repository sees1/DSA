#include <vector>
#include <algorithm>
#include <numeric>
#include <gtest/gtest.h>

std::vector<int> minSubsequence(std::vector<int>& nums) {
  std::sort(nums.begin(), nums.end(), std::greater<int>());
  int acc = std::accumulate(nums.begin(), nums.end(), 0);
  std::vector<int> prefix_sum ;
  std::partial_sum(nums.begin(), nums.end(), std::back_inserter(prefix_sum));
  int half = acc / 2;
  auto it = std::upper_bound(prefix_sum.begin(), prefix_sum.end(), half);
  size_t dist = std::distance(prefix_sum.begin(), it);
  it = nums.begin();
  std::advance(it, dist + 1);
  return std::vector<int>(nums.begin(), it);
}

TEST(DynamicTest, Test1)
{
  std::vector<int> nums = {4, 3, 10, 9, 8};
  std::vector<int> res = {10, 9};
  EXPECT_EQ(minSubsequence(nums), res);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}