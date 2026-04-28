#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

int fillCups(std::vector<int>& amount) {
  std::sort(amount.begin(), amount.end(), std::greater<int>());

  int res = 0;
  while(amount[0] != 0 && amount[1] != 0)
  {
    res += amount[1];
    amount[0] -= amount[1];
    amount[1] -= amount[1];
    std::sort(amount.begin(), amount.end(), std::greater<int>());
  }

  return res + amount[0];
}

TEST(DynamicTest, Test1)
{
  std::vector<int> amount = {5, 4, 4};
  EXPECT_EQ(fillCups(amount), 7);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}