#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <limits>
#include <gtest/gtest.h>

std::string keyFromVector(std::vector<int>& choose)
{
  std::string res;
  for(auto& num : choose)
    num == -1 ? res += "F" : res += "T";

  return res;
}

bool can_win(std::unordered_map<std::string, bool>& dp, std::vector<int>& choose, int desired_total)
{
  std::string key = keyFromVector(choose);
  
  if (dp.count(key))
    return dp[key];

  int max_el = *std::max_element(choose.begin(), choose.end());
  if (max_el >= desired_total)
    return dp[key] = true;

  for(int i = 1; i < choose.size(); ++i)
  {
    if(choose[i] == -1)
      continue;
    else
    {
      int tmp = choose[i];
      choose[i] = -1;
      if (!can_win(dp, choose, desired_total - tmp))
      {
        choose[i] = tmp;
        return dp[key] = true;
      }
      choose[i] = tmp;
    }
  }

  return dp[key] = false;
}

bool canIWin(int max_choosable_int, int desired_total) {
  if (desired_total <= 0)
    return true;

  std::vector<int> choose(max_choosable_int + 1, 0);
  for(int i = 1; i < max_choosable_int + 1; ++i)
    choose[i] = i;

  int acc = std::accumulate(choose.begin(), choose.end(), 0);
  if (acc < desired_total)
    return false;

  std::unordered_map<std::string, bool> dp;

  return can_win(dp, choose, desired_total);
}

TEST(DynamicTest, Test1)
{
  int max_choosable_int = 10;
  int desired_total = 11;
  EXPECT_EQ(canIWin(max_choosable_int, desired_total), false);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}