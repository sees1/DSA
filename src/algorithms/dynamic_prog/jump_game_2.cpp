#include <vector>
#include <chrono>
#include <algorithm>
#include <gtest/gtest.h>

struct greedy_tag {};
struct dynamic_tag {};

template<typename Tag>
int jump(std::vector<int>& nums) { return 0; }

template<>
int jump<greedy_tag>(std::vector<int>& nums)
{
  int far = 0;
  int near = 0;
  int jumps = 0;
  while (far < nums.size() - 1)
  {
    int next_far = 0;
    for(int i = near; i <= far; ++i)
      next_far = std::max(next_far, i + nums[i]);

    near = far + 1;
    far = next_far;
    ++jumps;
  }

  return jumps;
}

int solveJump(std::vector<int>& nums, std::vector<int>& dp, int pos)
{
  if (pos >= nums.size() - 1)
    return 0;
  
  if (dp[pos] != 10001)
    return dp[pos];

  for(int i = 1; i <= nums[pos]; ++i)
    dp[pos] = std::min(dp[pos], 1 + solveJump(nums, dp, pos + i));

  return dp[pos];
}

template<>
int jump<dynamic_tag>(std::vector<int>& nums)
{
  std::vector<int> dp(nums.size(), 10001);
  return solveJump(nums, dp, 0);
}

TEST(GreedyTest, Test1)
{
  std::vector<int> nums = {2, 3, 1, 1, 4};
  EXPECT_EQ(jump<greedy_tag>(nums), 2);
}

TEST(GreedyTest, Test2)
{
  std::vector<int> nums = {2, 1};
  EXPECT_EQ(jump<greedy_tag>(nums), 1);
}

TEST(DynamicTest, Test1)
{
  std::vector<int> nums = {2, 3, 1, 1, 4};
  EXPECT_EQ(jump<dynamic_tag>(nums), 2);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}