#include <vector>
#include <deque>
#include <array>
#include <string>
#include <unordered_map>
#include <algorithm>

struct naive_tag {};
struct eff_tag {};

template<typename Tag>
std::vector<std::vector<int>> diagonalSort(std::vector<std::vector<int>>& mat) { }

template<>
std::vector<std::vector<int>> diagonalSort<naive_tag>(std::vector<std::vector<int>>& mat)
{
  std::array<int, 2> resolution;
  resolution[0] = mat.size();
  resolution[1] = mat[0].size();
  for(int dim = 0; dim < 2; ++dim)
  {
    size_t dim_resolution = resolution[dim];

    for(int iter = dim; iter < dim_resolution; ++iter)
    {
      std::deque<int> diagonal;

      int row;
      int column;

      if (dim == 0)
      {
        row = iter;
        column = 0;
      }
      else
      {
        row = 0;
        column = iter;
      }

      while(row < resolution[0] && column < resolution[1])
      {
        diagonal.push_back(mat[row][column]);
        ++row;
        ++column;
      }

      std::sort(diagonal.begin(), diagonal.end());

      if (dim == 0)
      {
        row = iter;
        column = 0;
      }
      else
      {
        row = 0;
        column = iter;
      }

      while(row < resolution[0] && column < resolution[1])
      {
        mat[row][column] = diagonal.front();
        diagonal.pop_front();
        ++row;
        ++column;
      }
    }
  }

  return mat;
}

template<>
std::vector<std::vector<int>> diagonalSort<eff_tag>(std::vector<std::vector<int>>& mat) {
  int m = mat.size();
  int n= mat[0].size();

  std::unordered_map<int, std::vector<int>>mp;
  for(int i =0; i < m;i++){
    for(int j =0; j<n;j++){
        mp[i-j].push_back(mat[i][j]);
    }
  }

  for(auto &it : mp){
    sort(it.second.begin(), it.second.end());
  }

  for(int i = m-1; i>=0;i--){
    for(int j = n-1;j>=0;j--){
        mat[i][j] = mp[i-j].back();
        mp[i-j].pop_back();
    }
  }

  return mat;
}

int main() {
  std::vector<std::vector<int>> mat = {{3,3,1,1},{2,2,1,2},{1,1,1,2}};

  auto res = diagonalSort<naive_tag>(mat);
}