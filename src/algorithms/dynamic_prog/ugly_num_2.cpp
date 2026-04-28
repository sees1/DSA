#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <gtest/gtest.h>

int nthUglyNumber(int n)
{
  std::vector<int> dp(n + 1);
  dp[1] = 1;

  int two_idx = 1;
  int three_idx = 1;
  int five_idx = 1;

  for(int i = 2; i <= n; ++i)
  {
    int second_gen = dp[two_idx] * 2;
    int third_gen = dp[three_idx] * 3;
    int fifth_gen = dp[five_idx] * 5;

    int ugly = std::min({second_gen, third_gen, fifth_gen});

    dp[i] = ugly;

    if(ugly == second_gen) two_idx++;
    if(ugly == third_gen)  three_idx++;
    if(ugly == fifth_gen)  five_idx++;
  }

  return dp[n];
}

TEST(DynamicTest, Test1)
{
  int n = 10;
  EXPECT_EQ(nthUglyNumber(n), 12);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}