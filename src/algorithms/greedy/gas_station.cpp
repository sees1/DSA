#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
  int total = 0;
  int curr = 0;
  int start = 0;
  
  for(int i = 0; i < gas.size(); ++i)
  {
    int diff = gas[i] - cost[i];
    total += diff;
    curr += diff;

    if (curr < 0)
    {
      start = i + 1;
      curr = 0;
    }
  }

  return total >= 0 ? start : -1;
}

TEST(DynamicTest, Test1)
{
  std::vector<int> gas = {1, 2, 3, 4, 5};
  std::vector<int> cost = {3, 4, 5, 1, 2};
  EXPECT_EQ(canCompleteCircuit(gas, cost), 3);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}