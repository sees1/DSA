#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

int maxDistance(std::vector<std::vector<int>>& arrays) {
  int global_min = arrays[0][0];
  int global_max = arrays[0].back();

  int max_dist = 0;
  for(int i = 1; i < arrays.size(); ++i)
  {
    int local_min = arrays[i][0];
    int local_max = arrays[i].back();

    max_dist = std::max(max_dist, std::max(local_max - global_min, global_max - local_min));

    global_min = std::min(global_min, local_min);
    global_max = std::max(global_max, local_max);
  }

  return max_dist;
}

TEST(DynamicTest, Test1)
{
  std::vector<std::vector<int>> nums = {{1, 2, 3}, {4, 5}, {1, 2, 3}};
  EXPECT_EQ(maxDistance(nums), 4);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}