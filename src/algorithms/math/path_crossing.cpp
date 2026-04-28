#include <string>
#include <vector>
#include <algorithm>

auto operator+(std::pair<int, int>& lhs, std::pair<int, int>& rhs)
{
  return std::make_pair(lhs.first + rhs.first, lhs.second + rhs.second);
}

bool isPathCrossing(std::string path) {
  std::vector<std::pair<int, int>> coords;

  coords.push_back({0, 0});

  for(auto& dir : path)
  {
    std::pair<int, int> coord;
    if (dir == 'N')
        coord = {0, 1};
    else if (dir == 'S')
        coord = {0, -1};
    else if (dir == 'E')
        coord = {1, 0};
    else
        coord = {-1, 0};

    auto& back_el = coords.back();

    auto new_el = back_el + coord;

    if (std::find(coords.begin(), coords.end(), new_el) != coords.end())
      return true;
    else
      coords.push_back(new_el);
  }

  return false;
}

int main() { 
  std::string path = "NEW";
  auto res = isPathCrossing(path);
}