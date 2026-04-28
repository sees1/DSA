#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>

std::vector<int> memo;

int digit(std::string& s, size_t index)
{
  size_t size = s.size();

  if (index >= size)
    return 1;
  else if (memo[index] != -1)
    return memo[index];

  int ways = 0;

  if (s[index] != '0')
    ways = digit(s, index + 1);

  if (index + 1 < size && ((s[index] == '1' && s[index + 1] <= '9') ||
                            s[index] == '2' && s[index + 1] <= '6'))
  {
    ways += digit(s, index + 2);
  }

  memo[index] = ways;

  return ways;
}

int prepare(std::string& s)
{
  memo.resize(s.size(), -1);
  return digit(s, 0);
}

int main() {
  std::string s = "1234";
  std::cout << prepare(s);
}