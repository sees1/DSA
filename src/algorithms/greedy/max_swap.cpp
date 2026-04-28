#include <vector>
#include <stack>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

int maximumSwap(int num)
{
  std::vector<int> num_v;
  while(num != 0)
  {
    num_v.push_back(num % 10);
    num = num / 10;
  }
  std::reverse(num_v.begin(), num_v.end());

  std::stack<std::pair<int, int>> max;
  int local_max = 0;
  for(int i = num_v.size() - 1; i >= 0; --i)
  {
    if (num_v[i] > local_max)
    {
      local_max = num_v[i];
      max.push({local_max, i});
    }
  }

  for(int i = 0; i < num_v.size() && !max.empty(); ++i)
  {
    if (i < max.top().second)
    {
      if (num_v[i] < max.top().first)
      {
        std::swap(num_v[i], num_v[max.top().second]);
        break;
      }
    }
    else
      max.pop();
  }

  int rank = 1;
  int res = 0;
  while(!num_v.empty())
  {
    res += rank * num_v.back();
    num_v.pop_back();
    rank *= 10;
  }

  return res;
}

TEST(DynamicTest, Test1)
{
  EXPECT_EQ(maximumSwap(12335431), 10);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}