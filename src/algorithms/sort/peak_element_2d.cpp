#include <vector>
#include <string>
#include <utility>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

std::pair<int, int> findPeakGrid(const std::vector<std::vector<int>>& grid)
{
  if (grid.empty())
    return {0, 0};

  int left_col = 0;
  int right_col = grid[0].size() - 1;

  while(left_col <= right_col)
  {
    int mid_col = left_col + (right_col - left_col) / 2;

    // linear search (control of peak inside column)
    int max_idx = 0;
    int max = std::numeric_limits<int>::min();
    for(int idx = 0; idx < grid.size(); ++idx)
    {
      if (grid[idx][mid_col] > max)
      {
        max = grid[idx][mid_col];
        max_idx = idx;
      }
    }

    int lhs_el = (mid_col > 0) ? grid[max_idx][mid_col - 1] : std::numeric_limits<int>::min();
    int rhs_el = (mid_col + 1 < grid[0].size()) ? grid[max_idx][mid_col + 1] : std::numeric_limits<int>::min();

    if (lhs_el <= grid[max_idx][mid_col] && grid[max_idx][mid_col] >= rhs_el)
      return {max_idx, mid_col};

    if (grid[max_idx][mid_col] < rhs_el)
      left_col = mid_col + 1;
    else
      right_col = mid_col - 1;
  }

  return {-1, -1};
}

TEST(DynamicTest, Test1)
{
  std::vector<std::vector<int>> nums = {{10, 20, 15},
                                        {21, 30, 14},
                                        {7,  16, 32}};

  EXPECT_EQ(findPeakGrid(nums), (std::pair<int, int>(1, 1)));
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}