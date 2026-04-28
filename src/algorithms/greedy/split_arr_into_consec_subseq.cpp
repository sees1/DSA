#include <vector>
#include <unordered_map>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

bool isPossible(std::vector<int>& nums)
{
  std::unordered_map<int, int> freq_map;
  for(auto& n : nums)
    freq_map[n]++;

  std::unordered_map<int, int> need_map;
  for(auto& n : nums)
  {
    if (freq_map[n] == 0)
      continue;

    if (need_map[n] > 0)
    {
      freq_map[n]--;
      need_map[n]--;

      need_map[n + 1]++;
    }
    else if (freq_map[n] > 0 && freq_map[n + 1] > 0 && freq_map[n + 2] > 0)
    {
      freq_map[n]--;
      freq_map[n + 1]--;
      freq_map[n + 2]--;

      need_map[n + 3]++;
    }
    else
      return false;
  }

  return true;
}

TEST(DynamicTest, Test1)
{
  std::vector<int> nums = {1, 2, 3, 3, 4, 5};
  EXPECT_EQ(isPossible(nums), true);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}