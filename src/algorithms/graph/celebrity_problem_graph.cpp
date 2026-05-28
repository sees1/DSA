#include <vector>
#include <string>
#include <numeric>
#include <gtest/gtest.h>

// n^2 time complexity for celebrity problem solve by represent task as a graph
int celebrity(std::vector<std::vector<int>>& mat)
{
  std::vector<int> outdegree(mat.size(), 0);
  std::vector<int> indegree(mat.size(), 0);

  for(int row = 0; row < mat.size(); ++row)
  {
    for(int col = 0; col < mat.size(); ++col)
    {
      int add = mat[row][col];

      outdegree[row] += add;
      indegree[col] += add;
    }
  }

  // indegree - all (equal to n), outdegree - only themselves (equal to 1)
  for(int idx = 0; idx < mat.size(); ++idx)
  {
    if (outdegree[idx] == 1 && indegree[idx] == mat.size())
      return idx;
  }

  return -1
}

TEST(Graph, Test1)
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