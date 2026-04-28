#include <vector>
#include <string>
#include <limits>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <gtest/gtest.h>

struct Solution {
std::pair<int, int> convert(std::string& s)
{
  int zero = 0;
  int one = 0;
  for(auto& c : s)
    c == '1' ? ++one : ++zero;
  
  return {zero, one};
}

int solve(std::vector<std::vector<std::vector<int>>>& dp, std::vector<std::pair<int, int>>& zero_one, int rem_zero, int rem_one, int pos)
{
  if (pos == zero_one.size() || (rem_zero == 0 && rem_one == 0))
    return 0;

  if(zero_one[pos].first > rem_zero || zero_one[pos].second > rem_one)  
    return solve(dp, zero_one, rem_zero, rem_one, pos + 1);

  if (dp[pos][rem_zero][rem_one] != -1)
    return dp[pos][rem_zero][rem_one];  
  
  int pick = 1 + solve(dp, zero_one, rem_zero - zero_one[pos].first, rem_one - zero_one[pos].second, pos + 1);
  int dont_pick = solve(dp, zero_one, rem_zero, rem_one, pos + 1);

  return dp[pos][rem_zero][rem_one] = std::max(pick, dont_pick);
}

int findMaxForm(std::vector<std::string>& strs, int m, int n) {
  std::vector<std::pair<int, int>> zero_one;
  std::transform(strs.begin(), strs.end(), std::back_inserter(zero_one), [this](auto& el)
  {
      return convert(el);
  });

  std::vector<std::vector<std::vector<int>>> dp(strs.size(), std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, -1)));
  return solve(dp, zero_one, m, n, 0);
}
};

TEST(DynamicTest, Test1)
{
  Solution s;
  std::vector<std::string> strs = {"10", "0001", "111001", "1", "0"};
  EXPECT_EQ(s.findMaxForm(strs, 5, 3), 4);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}