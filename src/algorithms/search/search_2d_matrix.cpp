#include <iostream>
#include <vector>
#include <optional>

struct another_way;

template <typename T = void>
bool searchMatrix(std::vector<std::vector<int>>& matrix, int target)
{
  int top_row = 0;
  int bottom_row = matrix.size() - 1;

  while(bottom_row - top_row > 1)
  {
    int mid = (top_row + bottom_row) / 2;

    if (matrix[mid][0] == target)
      return true;

    if (matrix[mid][0] > target)
      bottom_row = mid;
    else
      top_row = mid;
  }

  int needed_row;

  if (target <= matrix[top_row][matrix[top_row].size() - 1])
    needed_row = top_row;
  else
    needed_row = bottom_row;

  int left = 0;
  int right = matrix[needed_row].size() - 1;

  while(left <= right)
  {
    int mid = (left + right) / 2;

    if (matrix[needed_row][mid] == target)
      return true;
    else if (matrix[needed_row][mid] < target)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }

  return false;
}

template <>
bool searchMatrix<another_way>(std::vector<std::vector<int>>& matrix, int target)
{
  int lo = 0;
  int hi = matrix.size() - 1;
  std::optional<int> row;

  while(lo <= hi)
  {
    int mid = lo + (hi - lo) / 2;

    if (matrix[mid][0] == target)
      return true;

    if (target < matrix[mid][0])
      hi = mid - 1;
    else
    {
      row = mid;
      lo = mid + 1;
    }
  }

  if (!row.has_value())
    return false;

  lo = 0;
  hi = matrix[0].size() - 1;

  while(lo <= hi)
  {
    int mid = lo + (hi - lo) / 2;

    if (matrix[*row][mid] == target)
      return true;

    if (target < matrix[*row][mid])
      hi = mid - 1;
    else
      lo = mid + 1;
  }

  return false;
}

int main () {
  std::vector<std::vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
  int target = 3;
  auto res = searchMatrix(matrix, target);
}