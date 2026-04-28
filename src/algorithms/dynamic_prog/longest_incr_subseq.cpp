#include <vector>
#include <limits>
#include <algorithm>

int lengthOfLIS(std::vector<int>& nums)
{
  int n = nums.size();
  std::vector<int> dp(n, 1);
  for(int i = 0; i < n; ++i)
  {
    for(int j = 0; j < i; ++j)
    {
      if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
        dp[i] = dp[j] + 1;
    }
  }

  return *std::max_element(dp.begin(), dp.end());
}

int main() {
  std::vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

  auto res = lengthOfLIS(nums);
}