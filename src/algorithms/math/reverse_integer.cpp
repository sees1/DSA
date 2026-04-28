#include <deque>
#include <cmath>
#include <limits>

int reverse(int x)
{
  std::deque<int> nums;
  bool sig = false;

  if (x < 0)
  {
    sig = true;
    nums.push_back(x % 10);
    nums[0] = std::abs(nums[0]);
    x = x / 10;
    x = std::abs(x);
  }

  while (x != 0)
  {
    nums.push_back(x % 10);
    x = x / 10;
  }

  if (nums.size() == 10)
  {
    int left = 0;
    int right = 5;

    int left_res = 0;
    int right_res = 0;

    while(left < 5)
    {
      int left_digit = nums[left];
      int right_digit = nums[right];

      left_res = left_res * 10 + left_digit;
      right_res = right_res * 10 + right_digit;

      ++left;
      ++right;
    }

    if (left_res > 21474)
      return 0;

    if (sig)
    {
      if (right_res > 83648)
        return 0;
    }
    else
    {
      if (right_res > 83647)
        return 0;
    }
  }

  int res = 0;
  while (!nums.empty())
  {
    int digit = nums.front();
    nums.pop_front();
    res = res * 10 + digit;
  }

  if (sig)
    res *= -1;

  return res;
}

int main() {
  int x = 1563847412;
  auto res = reverse(x);
}