#include <iostream>
#include <vector>
#include <unordered_map>

bool checkSubarraySum(std::vector<int>& nums, int k) {
  std::unordered_map<int, int> prefix;
  prefix[0] = -1;

  int prefix_sum = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    prefix_sum += nums[i];

    int remainder = prefix_sum % k;
    if (remainder < 0)
      remainder += k;

    if (prefix.find(remainder) != prefix.end())
    {
      if (i - prefix[remainder] > 1)
        return true;
    }
    else
      prefix[remainder] = i;
  }

  return false;
}

int main() {
  std::vector<int> nums = {5, 0, 0, 0};
  int k = 3;

  auto res = checkSubarraySum(nums, k);
}