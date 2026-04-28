#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <limits>
#include <gtest/gtest.h>

int findMinArrowShots(std::vector<std::vector<int>>& points) {
  std::sort(points.begin(), points.end(), [](auto& lhs, auto& rhs)
  {
      return lhs[1] < rhs[1];
  });

  int arr = 0;
  int i = 0;
  while(i < points.size())
  {
    int diff = 1;
    while (i + diff < points.size() && points[i][1] >= points[i + diff][0])
    {
      ++diff;
    }
    i += diff;
    ++arr;
  }

  return arr;
}

TEST(DynamicTest, Test1)
{
  std::vector<std::vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
  EXPECT_EQ(findMinArrowShots(points), 2);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}