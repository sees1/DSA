#include <vector>
#include <string>
#include <algorithm>
#include <limits>

int minSubArrayLen(int target, std::vector<int>& nums)
{
  std::vector<int> prefix(nums.size() + 1, 0);

  int left = 0;
  int res = std::numeric_limits<int>::max();
  for(int right = 1; right <= nums.size(); ++right)
  {
    prefix[right] = prefix[right - 1] + nums[right - 1];

    while (left < right)
    {
      if (prefix[right] - target >= prefix[left])
      {
        res = std::min(res, right - left);
        left++;
      }
      else
        break;
    }
  }

  return res == std::numeric_limits<int>::max() ? 0 : res;
}

int main() { 
  std::vector<int> nums = {2, 3, 1, 2, 4, 3};
  int target = 7;

  auto res = minSubArrayLen(target, nums);
}