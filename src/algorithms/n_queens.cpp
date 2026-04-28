#include <vector>
#include <string>

class Solution {
public:
  std::vector<std::pair<int, int>> queens;
  int size;
public:
  
  void placeQueen(int row, int col)
  {
      queens.push_back(std::make_pair(row, col));
  }
  
  void removeQueen(int row, int col)
  {
      for(size_t el = 0; el < queens.size(); ++el)
          if (queens[el].first == row && queens[el].second == col)
              queens.erase(queens.begin() + el);
  }
  
  bool isUnderAttack(int row, int col)
  {
      for(size_t el = 0; el < queens.size(); ++el)
      {
          if (queens[el].second == col)
              return true;
          
          int queen_attack_row = queens[el].first;
          int queen_attack_col = queens[el].second;
          
          while (queen_attack_row < size && queen_attack_col < size)
          {
              if (row == queen_attack_row && col == queen_attack_col)
                  return true;
              
              ++queen_attack_row;
              ++queen_attack_col;
          }
          
          queen_attack_col = queens[el].second;
          queen_attack_row = queens[el].first;
          
          while (queen_attack_row >= 0 && queen_attack_col >= 0)
          {
              if (row == queen_attack_row && col == queen_attack_col)
                  return true;
              
              --queen_attack_row;
              --queen_attack_col;
          }

          queen_attack_col = queens[el].second;
          queen_attack_row = queens[el].first;

          while (queen_attack_row < size && queen_attack_col < size)
          {
              if (row == queen_attack_row && col == queen_attack_col)
                  return true;
              
              ++queen_attack_row;
              --queen_attack_col;
          }
          
          queen_attack_col = queens[el].second;
          queen_attack_row = queens[el].first;
          
          while (queen_attack_row >= 0 && queen_attack_col >= 0)
          {
              if (row == queen_attack_row && col == queen_attack_col)
                  return true;
              
              --queen_attack_row;
              ++queen_attack_col;
          }
      }
      
      return false;
  }
  
  int subQueens(int row, int size)
  {
      int count = 0;
      
      for(int col = 0; col < size; ++col)
      {
          if (!isUnderAttack(row, col))
          {
              placeQueen(row, col);
              
              if (row == size - 1)
              {
                removeQueen(row, col);
                return 1;
              }
              else
                count += subQueens(row + 1, size);
              
              removeQueen(row, col);
          }
      }
      
      return count;
  }
      
      
  int totalNQueens(int n) {
      size = n;
      return subQueens(0, n);
  }
};

int main()
{
  Solution s;
  s.totalNQueens(4);
}