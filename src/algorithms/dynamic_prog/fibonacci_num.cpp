#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>


std::vector<int> fib_array;

int fibonacci(int n)
{
  if (n <= 1)
    return n;

  int fib1, fib2;

  if (fib_array[n - 1] != -1)
    fib1 = fib_array[n - 1];
  else
    fib1 = fib_array[n - 1] = fibonacci(n - 1);

  if (fib_array[n - 2] != -1)
    fib2 = fib_array[n - 2];
  else
    fib2 = fib_array[n - 2] = fibonacci(n - 2);

  fib_array[n] = fib1 + fib2;

  return fib_array[n];
}

int nthFibonacciUtil(int n, std::vector<int>& memo) 
{
  if (n <= 1)
    return n;

  if (memo[n] != -1)
    return memo[n];

  memo[n] = nthFibonacciUtil(n - 1, memo) + nthFibonacciUtil(n - 2, memo);

  return memo[n];
}

int main () {
  int n = 8;
  fib_array.resize(n);
  std::fill(fib_array.begin(), fib_array.end(), -1);
  fibonacci(n);

  std::vector<int> memo(n + 1, -1);
  nthFibonacciUtil(n, memo);
}