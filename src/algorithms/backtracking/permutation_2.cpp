#include <vector>
#include <string>
#include <numeric>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <gtest/gtest.h>

void backtrack(const std::vector<int>& nums, 
               std::vector<int>& combo,
               std::vector<std::vector<int>>& combins,
               std::unordered_map<int, int>& freq)
{
  if (combo.size() == nums.size())
  {
    combins.push_back(combo);
    return;
  }

  for(auto& pair : freq)
  {
    if (pair.second == 0 )
      continue;

    pair.second--;
    combo.push_back(pair.first);
    backtrack(nums, combo, combins, freq);
    combo.pop_back();
    pair.second++;
  }
}

std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
  std::unordered_map<int, int> freq_map;
  for(auto& n : nums)
    freq_map[n]++;

  std::vector<std::vector<int>> combins;
  std::vector<int> combo;
  backtrack(nums, combo, combins, freq_map);
  return combins;
}

TEST(DynamicTest, Test1)
{
  std::vector<int> nums = {1, 1, 2};
  std::vector<std::vector<int>> res = {{1, 1, 2}, {1, 2, 1}, {2, 1, 1}}; 
  EXPECT_EQ(permuteUnique(nums), res);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}