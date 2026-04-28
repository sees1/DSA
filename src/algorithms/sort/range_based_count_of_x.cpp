#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

std::vector<int> countXInRange(const std::vector<int>& arr, std::vector<std::vector<int>>& queries)
{
  std::vector<int> result;

  for(auto& query : queries)
  {
    int left = query[0];
    int right = query[1];
    int target = query[2];

    auto l_bound = std::lower_bound(arr.begin() + left, arr.begin() + right + 1, target);
    auto r_bound = std::upper_bound(arr.begin() + left, arr.begin() + right + 1, target);
    int l_bound_addr = std::distance(arr.begin(), l_bound);
    int r_bound_addr = std::distance(arr.begin(), r_bound);
    r_bound_addr--; // last equal if exist (if not exist right bound will less than left what automaticaly give us zero in result)


    if (r_bound_addr < l_bound_addr)
      result.push_back(0);
    else
      result.push_back(r_bound_addr - l_bound_addr + 1);
  }

  return result;
}

TEST(SearchTest, Test1)
{
  std::vector<int> nums = {1, 2, 2, 4, 5, 5, 5, 8};
  std::vector<std::vector<int>> queries = {{0, 7, 5}, {1, 2, 2}, {0, 3, 7}};

  std::vector<int> res = {3, 2, 0};
  EXPECT_EQ(countXInRange(nums, queries), res);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}