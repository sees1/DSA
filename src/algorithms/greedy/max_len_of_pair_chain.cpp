#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

int findLongestChain(std::vector<std::vector<int>>& pairs)
{
  std::sort(pairs.begin(), pairs.end(), [](auto& lhs, auto& rhs)
  {
    return lhs[1] < rhs[1];
  });

  int res = 0;
  int left = 0;
  for(int right = 1; right < pairs.size(); ++right)
  {
    if (pairs[right][0] > pairs[left][1])
    {
      left = right;
      ++res;
    }
  }

  return res + 1;
}

TEST(DynamicTest, Test1)
{
  std::vector<std::vector<int>> pairs = {{1, 2}, {2, 3}, {3, 4}};
  EXPECT_EQ(findLongestChain(pairs), 2);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}