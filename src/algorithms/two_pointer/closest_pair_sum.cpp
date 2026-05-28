#include <vector>
#include <limits>
#include <cmath>
#include <gtest/gtest.h>

std::pair<int, int> closestPair(std::vector<int>& a, std::vector<int>& b, int x)
{
  int left = 0;
  int right = b.size() - 1;
  int min_diff = std::numeric_limits<int>::max();
  std::pair<int, int> res;

  while(left < a.size() && right >= 0)
  {
    int sum = a[left] + b[right];
    int diff = std::abs(x - sum);

    if (diff < min_diff)
    {
      min_diff = diff;
      res.first = a[left];
      res.second = b[right];
    }

    if (sum > x)
      right--;
    else 
      left++;
  }

  return res;
}

TEST(TwoPointer, Test1)
{
  std::vector<int> a = {1, 4, 5, 7};
  std::vector<int> b = {10, 20, 30, 40};
  std::pair<int, int> res = {7, 40};
  EXPECT_EQ(closestPair(a, b, 50), res);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}