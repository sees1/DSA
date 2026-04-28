#include <vector>
#include <numeric>
#include <string>

std::vector<std::pair<int, int>> intervalIntersection(std::vector<std::pair<int, int>>& first, std::vector<std::pair<int, int>>& second)
{
  size_t first_idx = 0, second_idx = 0;

  size_t first_s = first.size();
  size_t second_s = second.size();

  auto interval = [](std::pair<int, int>& lhs, std::pair<int, int>& rhs) -> std::pair<int, int>
  {
    int start = std::max(lhs.first, rhs.first);
    int end = std::min(lhs.second, rhs.second);

    return {start, end};
  };

  std::vector<std::pair<int, int>> res;

  while(first_idx != first_s && second_idx != second_s)
  {
    std::pair<int, int> inter = interval(first[first_idx], second[second_idx]);

    if (inter.second >= inter.first)
    {
      res.push_back(inter);
    }

    if (first[first_idx].second < second[second_idx].second)
      ++first_idx;
    else
      ++second_idx;
  }

  return res;
}


int main() {
  std::vector<std::pair<int, int>> first = {{0, 2}, {5, 10}, {13, 23}, {24, 25}};
  std::vector<std::pair<int, int>> second = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};

  auto res = intervalIntersection(first, second);
}