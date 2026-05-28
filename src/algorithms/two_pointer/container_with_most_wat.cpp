#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <limits>
#include <gtest/gtest.h>

int maxArea(std::vector<int>& height)
{
  int left = 0;
  int right = height.size() - 1;
  int max_sq = std::numeric_limits<int>::min();

  while(left < right)
  {
    if (height[left] < height[right])
      max_sq = std::max(max_sq, ((right - left) * height[left++]));
    else
      max_sq = std::max(max_sq, ((right - left) * height[right--]));
  }

  return max_sq;
}

TEST(TwoPointer, Test1)
{
  std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  EXPECT_EQ(maxArea(height), 49);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}