#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <gtest/gtest.h>

struct newton_method;

template <typename T = void>
int nthRoot(int m, int n)
{
  int left = 0;
  int right = m;
  int res = 0;

  while(left <= right)
  {
    int mid = left + (right - left) / 2;

    int mid_root_n = std::pow(mid, n);
    if (mid_root_n == m)
      return mid;

    if (m < mid_root_n)
      right = mid - 1;
    else
      left = mid + 1;
  }

  return -1;
}

template <>
int nthRoot<newton_method>(int m, int n)
{
  const double eps = 1e3;

  double x_prev = rand() % 10;
  double diff = std::numeric_limits<double>::lowest();

  double x;

  while (diff > eps)
  {
    x = ((n - 1.0) * x_prev + m / std::pow(x_prev, n - 1)) / n;
    diff = std::abs(x - x_prev);
    x_prev = x;
  }

  return static_cast<int>(std::roundf(x));
}

TEST(SearchTest, Test1)
{
  int x = 27;
  EXPECT_EQ(nthRoot(x, 3), 3);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}