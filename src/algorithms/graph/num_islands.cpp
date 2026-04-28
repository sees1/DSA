#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <numeric>
#include <limits>

enum DIR {UP, DOWN, RIGHT, LEFT};

std::pair<int, int> indToDir(size_t i)
{
  if (i == 0)
    return {-1, 0};
  else if (i == 1)
    return {1, 0};
  else if (i == 2)
    return {0, 1};
  else if (i == 3)
    return {0, -1};
  else
  {
    return {std::numeric_limits<int>::max(), std::numeric_limits<int>::max()};
    std::cout << "Fuck you and your programm, nigga" << std::endl;
  }
}

void bfs(int row_idx, int col_idx, int rows, int cols,
         std::vector<std::vector<char>>& grid,
         std::vector<std::vector<bool>>& v_grid)
{
  std::queue<std::pair<int, int>> grid_set;

  grid_set.push({row_idx, col_idx});

  while(!grid_set.empty())
  {
    auto coord = grid_set.front();
    v_grid[coord.first][coord.second] = true;
    grid_set.pop();

    for(size_t i = 0; i < 4; ++i)
    {
      auto coord_plus = indToDir(i);
      auto coord_temp = std::make_pair(coord.first + coord_plus.first, coord.second + coord_plus.second);

      if (coord_temp.first > -1 && coord_temp.first < rows &&
          coord_temp.second > -1 && coord_temp.second < cols &&
          v_grid[coord_temp.first][coord_temp.second] == false &&
          grid[coord_temp.first][coord_temp.second] == '1')
      {
        grid_set.push(coord_temp);
      }
    }
  }
}

int numIslandsHelper(std::vector<std::vector<char>>& grid,
                     std::vector<std::vector<bool>>& v_grid)
{
  size_t rows = grid.size();
  size_t cols = grid[0].size();

  size_t ans = 0;

  for(size_t i = 0; i < rows; ++i)
  {
    for(size_t j = 0; j < cols; ++j)
    {
      if (grid[i][j] == '1' && v_grid[i][j] == false)
      {
        bfs(i, j, rows, cols, grid, v_grid);
        ans++;
      }
    }
  }

  return ans;
}

int numIslands(std::vector<std::vector<char>>& grid)
{
  std::vector<std::vector<bool>> v_grid(grid.size(), std::vector<bool>(grid[0].size(), false));

  return numIslandsHelper(grid, v_grid);
}

int main()
{
  std::vector<std::vector<char>> grid = {{'1', '1', '1', '1', '0'},
                                         {'1', '1', '0', '1', '0'},
                                         {'1', '1', '0', '0', '0'},
                                         {'0', '0', '0', '0', '0'}};

  return numIslands(grid);
}