#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

struct effic_tag {};

template <typename Tag = void>
bool increasingTriplet(std::vector<int>& nums)
{
  int min = std::numeric_limits<int>::max();
  int max = std::numeric_limits<int>::min();
 
  std::vector<int> min_el(nums.size());
  for(int i = 0; i < nums.size(); ++i)
  {
    min = std::min(min, nums[i]);
    min_el[i] = min;
  }
  std::vector<int> max_el(nums.size());
  for(int i = nums.size() - 1; i >= 0; --i)
  {
    max = std::max(max, nums[i]);
    max_el[i] = max;
  }

  for(int i = 0; i < nums.size(); ++i)
  {
    if (nums[i] < max_el[i] && nums[i] > min_el[i])
      return true;
  }

  return false;
}

template <>
bool increasingTriplet<effic_tag>(std::vector<int>& nums)
{
  int min1 = std::numeric_limits<int>::max();
  int min2 = std::numeric_limits<int>::max();

  for(int n : nums)
  {
    if(n <= min1)
      min1 = n;  // Update first minimum
    else if(n <= min2)
      min2 = n;  // Update second minimum
    else
      return true;  // Found a third number greater than both
  }

  return false;  // No triplet found
}

TEST(DynamicTest, Test1)
{
  std::vector<int> nums = {2, 1, 5, 0, 4, 6};
  EXPECT_EQ(increasingTriplet(nums), true);
}

TEST(DynamicTest, Test2)
{
  std::vector<int> nums = {2, 1, 5, 0, 4, 6};
  EXPECT_EQ(increasingTriplet<effic_tag>(nums), true);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}