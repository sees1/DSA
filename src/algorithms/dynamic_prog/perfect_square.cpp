#include <unordered_map>
#include <vector>
#include <cmath>
#include <limits>
#include <numeric>

struct TopDown {};
struct DownTop {}; // faster

std::unordered_map<int, int> least_psnc;

bool isPerfectSquare(int num)
{
  int root = std::sqrt(num);
  return root * root == num;
}

template <typename Tag>
int numSquares(int n) { return -1; }

template <>
int numSquares<TopDown>(int n)
{
  if(isPerfectSquare(n))
    return 1;

  int min_count = std::numeric_limits<int>::max();

  for (int num = 1; num * num < n; ++num)
  {
    int sq = num * num;

    int left;
    int right;

    if (least_psnc.count(sq) != 0)
      left = least_psnc[sq];
    else
    {
      left = numSquares<TopDown>(sq);
      least_psnc[sq] = left;
    }
    
    if (least_psnc.count(n - sq) != 0)
      right = least_psnc[n - sq];
    else
    {
      right = numSquares<TopDown>(n - sq);
      least_psnc[n - sq] = right;
    }
    

    if (left + right < min_count)
    {
      min_count = left + right;
    }
  }

  return min_count;
}

template <>
int numSquares<DownTop>(int n)
{
  if (n <= 0)
    return 0;

  std::vector<int> dp (n + 1, std::numeric_limits<int>::max());
  dp[0] = 0;
  for(int i = 1; i <= n; ++i)
  {
    for(int j = 1; j * j <= i; ++j)
    {
      int num = j * j;
      dp[i] = std::min(dp[i], dp[i - num] + 1);
    }
  }

  return dp[n];
}

int main() {
  least_psnc[1] = 1;
  int n = 18;
  auto res = numSquares<TopDown>(n);
}