#include <vector>
#include <iostream>

std::vector<std::vector<int>> memo;

bool possibleHelper(std::vector<int>& m, size_t index, int sum)
{
  if (sum < 0 || index >= m.size())
    return false;
  else if (sum == 0)
    return true;
  
  if (memo[index][sum] != -1)
    return memo[index][sum];
  
  return memo[index][sum] = possibleHelper(m, index + 1, sum) ||
                            possibleHelper(m, index + 1, sum - m[index]);
}

bool possible(std::vector<int>& m, int sum)
{
  return possibleHelper(m, 0, sum);
}


int main() {
  std::vector<int> m = {3, 34, 4, 12, 5, 2};
  int sum = 9;

  memo.resize(m.size(), std::vector<int>(sum + 1, -1));

  std::cout << possible(m, sum) << std::endl;
}