#include <vector>
#include <algorithm>

void rotate(std::vector<std::vector<int>>& matrix)
{
  for(int row = 0; row < matrix.size(); ++row)
  {
    for(int col = row; col < matrix[0].size(); ++col)
      std::swap(matrix[row][col], matrix[col][row]);
  }

  for(auto& row : matrix)
  {
    std::reverse(row.begin(), row.end());
  }
}

int main() {
  std::vector<std::vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
  rotate(mat);
}