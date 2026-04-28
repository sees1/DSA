#include <vector>
#include <algorithm>
#include <string>
#include <limits>
#include <gtest/gtest.h>

int nthSuperUglyNumber(int n, std::vector<int>& primes) {
  int m = primes.size();
  std::vector<int> dp(n, 0);
  std::vector<int> primes_idx(m, 0);
  dp[0] = 1;

  for(int i = 1; i < n; ++i)
  {
    long long ugly = std::numeric_limits<int>::max();

    for(int j = 0; j < m; ++j)
      ugly = std::min(ugly, static_cast<long long>(primes[j]) * dp[primes_idx[j]]);

    dp[i] = ugly;

    for(int j = 0; j < m; ++j)
      if (ugly == static_cast<long long>(primes[j]) * dp[primes_idx[j]])
        ++primes_idx[j];
  }

  return dp[n - 1];
}

TEST(DynamicTest, Test1)
{
  std::vector<int> primes = {2,7,13,19};
  EXPECT_EQ(nthSuperUglyNumber(12, primes), 32);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}