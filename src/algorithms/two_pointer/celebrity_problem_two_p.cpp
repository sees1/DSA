#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <gtest/gtest.h>

int celebrity(std::vector<std::vector<int>>& mat)
{
  int left = 0;
  int right = mat.size() - 1;

  while(left < right)
  {
    if (mat[left][right])
      left++;
    else
      right--;
  }

  for(int idx = 0; idx < mat.size(); ++idx)
  {
    if (idx == left)
      continue;

    if (mat[left][idx] || !mat[idx][left])
      return -1;
  }

  return left;
}

TEST(TwoPointer, Test1)
{
  std::vector<std::vector<int>> numbers = {{1, 1, 0},
                                           {0, 1, 0},
                                           {0, 1, 1}};
  EXPECT_EQ(celebrity(numbers), 1);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}