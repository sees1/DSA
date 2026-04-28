#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <gtest/gtest.h>

int maxProduct(std::vector<int>& nums)
{
  int res = std::numeric_limits<int>::min();

  int cur_max = 1;
  int cur_min = 1;

  for (int n : nums)
  {
    int temp = cur_max * n;
    cur_max = std::max({temp, cur_min * n, n});
    cur_min = std::min({temp, cur_min * n, n});

    res = std::max(res, cur_max);
  }

  return res;
}

TEST(DynamicTest, Test1)
{
  std::vector<int> nums = {2, 3, -2, 4};
  EXPECT_EQ(maxProduct(nums), 6);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}