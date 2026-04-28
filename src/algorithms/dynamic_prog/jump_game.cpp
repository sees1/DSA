#include <vector>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

struct dynamic_tag {};

template <typename Tag = void>
bool canJump(std::vector<int>& nums)
{
  int goal = nums.size() - 1;
  int current = goal - 1;

  while(current >= 0)
  {
    if (current + nums[current] >= goal)
    {
      goal = current;
    }
    current--;
  }

  return goal == 0;
}

bool solve(std::vector<int>& nums, std::vector<int>& dp, int pos)
{
  if (pos >= nums.size() - 1)
    return true;

  if (nums[pos] == 0)
    return false;

  if (dp[pos] != -1)
    return dp[pos];

  for(int i = 1; i <= nums[pos]; ++i)
  {
    if (pos + i < nums.size() && solve(nums, dp, pos + i))
      return dp[pos] = true;
  }

  return dp[pos] = false;
}

template <>
bool canJump<dynamic_tag>(std::vector<int>& nums)
{
  std::vector<int> dp(nums.size(), -1);
  return solve(nums, dp, 0);
}

TEST(BasicTest, Test1)
{
  std::vector<int> nums = {2, 3, 1, 1, 4};
  EXPECT_EQ(canJump(nums), true);
}

TEST(BasicTest, Test2)
{
  std::vector<int> nums = {3, 2, 1, 0, 4};
  EXPECT_EQ(canJump(nums), false);
}

TEST(BasicTest, Test3)
{
  std::vector<int> nums = {2, 0, 0};
  EXPECT_EQ(canJump(nums), false);
}

TEST(DynamicTest, Test1)
{
  std::vector<int> nums = {2, 3, 1, 1, 4};
  EXPECT_EQ(canJump<dynamic_tag>(nums), true);
}

TEST(DynamicTest, Test2)
{
  std::vector<int> nums = {3, 2, 1, 0, 4};
  EXPECT_EQ(canJump<dynamic_tag>(nums), false);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}