#include <vector>
#include <string>
#include <bitset>

bool judgeCircle(std::string moves) {
  int x = 0, y = 0;

  for (char move : moves) {
      if (move == 'R') x++;
      else if (move == 'L') x--;
      else if (move == 'U') y++;
      else y--;
  }
  return (x == 0 && y == 0);
}

int main() {
  std::string moves = "RRDD";
  auto res = judgeCircle(moves);
}