#include <vector>
#include <iostream>

std::vector<int> mem;

int climb(int n)
{
  if (n < 0)
    return 0;
  else if (n == 0)
    return 1;
  else if (mem[n] != -1)
    return mem[n];

  mem[n] = climb(n - 1) + climb(n - 2);
  return mem[n];  
}

int main() {
  int n = 2;
  mem.resize(3, -1);

  std::cout << climb(n);
}