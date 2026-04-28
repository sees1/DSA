#include <set>
#include <numeric>
#include <iostream>
#include <limits>


bool lineReflect(std::set<std::pair<int, int>>& original_point_set)
{
  int max = std::numeric_limits<int>::min();
  int min = std::numeric_limits<int>::max();
  for(auto& point : original_point_set)
  {
    if (point.first > max)
      max = point.first;
    if (point.first < min)
      min = point.first;
  }

  int c = min + max / 2;

  std::set<std::pair<int, int>> reflected_point_set;

  for(auto& point : original_point_set)
  {
    reflected_point_set.insert({2 * c - point.first, point.second});
  }

  return original_point_set == reflected_point_set;
}

int main() {

  std::set<std::pair<int, int>> in_set;

  in_set.insert({1, 1});
  in_set.insert({2, 1});

  std::cout << lineReflect(in_set);
}