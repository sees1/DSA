#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <cmath>
#include <algorithm>
#include <gtest/gtest.h>

int catchThiefs(std::vector<char>& arr, int k)
{
  int arr_s = static_cast<int>(arr.size());
  int p = 0;
  int t = 0;
  size_t res = 0;

  while(p < arr_s && t < arr_s)
  {
    while(p < arr_s && p != 'P')
      p++;

    while(t < arr_s && t != 'T')
      t++;

    if (p < arr_s && t < arr_s && std::abs(p - t) <= k)
    {
      res++;
      p++;
      t++;
    }
    else if (p < arr_s && p < t)
      p++;
    else if (t < arr_s)
      t++;
  }

  return res;
}

TEST(TwoPointer, Test1)
{
  std::vector<char> arr = {'P', 'T', 'T', 'P', 'T'};
  EXPECT_EQ(catchThiefs(arr, 1), 2);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}