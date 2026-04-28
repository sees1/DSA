#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <limits>

std::vector<std::vector<int>> memo;

int coinChangeHelper(const std::vector<int>& coins, int sum, size_t idx, std::vector<int>& subset)
{
  int curr_sum = std::accumulate(subset.begin(), subset.end(), 0);
  if(curr_sum == sum)
  {
    return subset.size();
  }
  else if (curr_sum > sum || idx >= coins.size())
  {
    return std::numeric_limits<int>::max();
  }

  if (memo[idx][curr_sum] != -1)
    return memo[idx][curr_sum];

  auto without_res = coinChangeHelper(coins, sum, idx + 1, subset);
  
  subset.push_back(coins[idx]);
  auto with_res = coinChangeHelper(coins, sum, idx + 1, subset);
  subset.pop_back();

  auto variants = std::min(without_res, with_res);

  memo[idx][curr_sum] = variants;

  return variants;
}

int coinChange(const std::vector<int>& coins, int sum)
{
  memo.resize(coins.size(), std::vector<int>(sum + 1, -1));
  std::vector<int> subset;
  return coinChangeHelper(coins, sum, 0, subset);
}

int main() {
  const std::vector<int> coins = {9, 6, 5, 1};

  std::cout << coinChange(coins, 19);
}