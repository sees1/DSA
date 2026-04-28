#include <vector>
#include <array>
#include <memory>
#include <cmath>
#include <iostream>

using std::vector;

class SubValidator {
protected:
  std::vector<std::vector<bool>> value_exist_table;
  size_t size;

public:
  SubValidator(size_t s)
  : size(s)
  {
    value_exist_table.resize(s);
    for(size_t i = 0; i < s; ++i)
    {
      value_exist_table[i].resize(s, false);
    }
  }

  virtual bool validate(int row, int col, int val) = 0;
  virtual void fillCell(int row, int col, int val, bool fl) = 0;
};

class RowValidator : public SubValidator {
public:
  RowValidator(size_t size)
  : SubValidator(size)
  { }

  bool validate(int row, int col, int val)
  {
    if (val > size || val < 1 || value_exist_table[row][val - 1])
      return false;
    
    return true;
  }

  void fillCell(int row, int col, int val, bool fl)
  {
    value_exist_table[row][val - 1] = fl;
  }
};

class ColumnValidator : public SubValidator {
public:
  ColumnValidator(size_t size)
  : SubValidator(size)
  { }

  bool validate(int row, int col, int val)
  {
    if (val > size || val < 1 || value_exist_table[col][val - 1])
      return false;

    return true;
  }

  void fillCell(int row, int col, int val, bool fl)
  {
    value_exist_table[col][val - 1] = fl;
  }
};

class BoxValidator : public SubValidator {
private:
  int square;

public:
  BoxValidator(size_t size)
  : SubValidator(size)
  {
    square = static_cast<int>(std::sqrt(static_cast<double>(size)));
  }

  int boxID(int row, int col)
  {
    return (row / square) * square + (col / square);
  }

  bool validate(int row, int col, int val)
  {
    int box_id = boxID(row, col);
    if (val > size || val < 1 || value_exist_table[box_id][val - 1])
      return false;

    return true;
  }

  void fillCell(int row, int col, int val, bool fl)
  {
    int box_id = boxID(row, col);
    value_exist_table[box_id][val - 1] = fl;
  }
};

class SudokuValidator {
private:
  std::array<std::shared_ptr<SubValidator>, 3> validators;

public:
  SudokuValidator(size_t size)
  {
    validators[0] = std::make_shared<RowValidator>(size);
    validators[1] = std::make_shared<ColumnValidator>(size);
    validators[2] = std::make_shared<BoxValidator>(size);
  }

  bool validate(int row, int col, int val)
  {
    bool valid = true;

    for(auto& validator : validators)
      valid &= validator->validate(row, col, val);
    
    return valid;
  }

  void fillCell(int row, int col, int val, bool fl)
  {
    for(auto& validator : validators)
      validator->fillCell(row, col, val, fl);
  }
};


class Solution {
private:
  std::shared_ptr<SudokuValidator> solver;

private:
  void fillSudoku(int row, int col, int val, std::vector<vector<char>>& board, bool fl)
  {
    board[row][col] = fl ? '0' + val : '.';
    solver->fillCell(row, col, val, fl);
  }

  bool solveSudoku(int row, int col, size_t board_size, vector<vector<char>>& board)
  {
    if (row == board_size)  return true;
    else if (col == board_size)  return solveSudoku(row + 1, 0, board_size, board);
    else if (board[row][col] != '.')  return solveSudoku(row, col + 1, board_size, board);

    for (int possible_val = 1; possible_val <= board_size; ++possible_val)
    {
      bool is_curr_val_possible = solver->validate(row, col, possible_val);
      if (!is_curr_val_possible)
        continue;
      fillSudoku(row, col, possible_val, board, true);
      bool is_solved = solveSudoku(row, col + 1, board_size, board);
      if (!is_solved)
        fillSudoku(row, col, possible_val, board, false);
      else
        return true;
    }

    return false;
  }

public:
  void solveSudoku(vector<vector<char>>& board) {
    size_t board_size = board.size();

    solver = std::make_shared<SudokuValidator>(board_size);

    for(size_t row = 0; row < board_size; ++row)
    {
      for(size_t col = 0; col < board_size; ++col)
      {
        if (board[row][col] == '.')
          continue;
        else if (!solver->validate(row, col, board[row][col] - '0'))
          throw std::runtime_error("Repeated integer detected while process board first time! Check board one more time before start solve");
        else
          solver->fillCell(row, col, board[row][col] - '0', true);
      }
    }

    if(!solveSudoku(0, 0, board_size, board))
      throw std::runtime_error("Sudoku haven't solution or error occurs while solve sudoku");
  }
};

std::ostream& operator<<(std::ostream& os, vector<vector<char>>& out)
{
  size_t size = out.size();
  for(size_t row = 0; row < size; ++row)
  {
    os << "---------------------------------------------";
    for(size_t col = 0; col < size; ++col)
    {
      os << "|" << out[row][col] << "|";
    }
    os << "---------------------------------------------";
    os << std::endl;
  }
}

int main() {
  Solution s;
  vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'}
                               ,{'6','.','.','1','9','5','.','.','.'}
                               ,{'.','9','8','.','.','.','.','6','.'}
                               ,{'8','.','.','.','6','.','.','.','3'}
                               ,{'4','.','.','8','.','3','.','.','1'}
                               ,{'7','.','.','.','2','.','.','.','6'}
                               ,{'.','6','.','.','.','.','2','8','.'}
                               ,{'.','.','.','4','1','9','.','.','5'}
                               ,{'.','.','.','.','8','.','.','7','9'}};
  s.solveSudoku(board);

  std::cout << board;
}