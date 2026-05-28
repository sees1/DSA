#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <gtest/gtest.h>

int minSwaps(const std::vector<int>& ones)
{
  int one_count = 0;
  for(int i = 0; i < ones.size(); ++i)
  {
    if (ones[i])
      one_count++;
  }

  int max_ones = 0;
  for(int i = 0; i < one_count; ++i)
  {
    if (ones[i])
      max_ones++;
  }

  int win_ones = max_ones;
  for(int i = one_count; i < ones.size(); ++i)
  {
    if (ones[i])
      win_ones++;
    
    if (ones[i - one_count])
      win_ones--;

    max_ones = std::max(win_ones, max_ones);
  }  

  return one_count - max_ones;
}

TEST(SlidingWindow, Test1)
{
  std::vector<int> ones = {1, 0, 1, 0, 1};
  EXPECT_EQ(minSwaps(ones), 1);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}