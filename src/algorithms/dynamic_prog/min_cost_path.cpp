#include <vector>
#include <iostream>
#include <limits>

std::vector<std::vector<int>> memo;

int minCost(int y_idx, int x_idx, std::vector<std::vector<int>> cell)
{
  if(x_idx > cell[0].size() - 1 || y_idx > cell.size() - 1)
    return 100000;
  else if (x_idx == cell[0].size() - 1 && y_idx == cell.size() - 1)
    return cell[y_idx][x_idx];
  else if (memo[y_idx][x_idx] != -1)
    return memo[y_idx][x_idx];

  int right = minCost(y_idx, x_idx + 1, cell);
  int diag = minCost(y_idx + 1, x_idx + 1, cell);
  int down = minCost(y_idx + 1, x_idx, cell);

  return memo[y_idx][x_idx] = cell[y_idx][x_idx] + std::min(std::min(right, diag), down);
}

int main() {
  std::vector<std::vector<int>> cell = {{1, 2, 3}, {4, 8, 2}, {1, 5, 3}};
  memo.resize(cell.size());

  for(size_t i = 0; i < memo.size(); ++i)
  {
    memo[i].resize(cell[i].size(), -1);
  }

  std::cout << minCost(0, 0, cell);
}