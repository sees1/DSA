#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

int backtrack(std::vector<int>& choosen, int k, int n)
{
  if (k < 1)
    return 1;

  int res = 0;

  for(int i = 0; i <= 9; ++i)
  {
    if(choosen[i] == 0 && (i != 0 || k != n))
    {
      choosen[i] = true;
      res += backtrack(choosen, k - 1, n);
      choosen[i] = false;
    }
  }

  return res;
}

int countNumbersWithUniqueDigits(int n)
{
  int res = 0;
  std::vector<int> choosen(10, 0);
  for(int i = 0; i <= n; ++i)
    res += backtrack(choosen, i, i);

  return res;
}

TEST(DynamicTest, Test1)
{
  int n = 2;
  EXPECT_EQ(countNumbersWithUniqueDigits(n), 91);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}