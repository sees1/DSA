#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

bool matSearch(const std::vector<std::vector<int>>& grid, int target)
{
  int row = 0;
  int col = grid[row].size() - 1;
  while(col >= 0 && row < grid.size())
  {
    if (grid[row][col] < target)
      row++;
    else if (grid[row][col] > target)
      col--;
    else
      return true;
  }

  return false;
}

TEST(SearchTest, Test1)
{
  std::vector<std::vector<int>> nums = {{3,  30, 38},
                                        {20, 52, 54},
                                        {35, 60, 69}};
  EXPECT_EQ(matSearch(nums, 52), true);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}