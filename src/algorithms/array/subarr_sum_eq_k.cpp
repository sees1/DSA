#include <unordered_map>
#include <vector>
#include <iostream>

int subarraySum(std::vector<int>& nums, int k)
{
  std::unordered_map<int, int> sum_to_count;

  int ans = 0;
  int sum = 0;

  sum_to_count[0] = 1;

  for(size_t idx = 0; idx < nums.size(); ++idx)
  {
    sum += nums[idx];

    if(sum_to_count.find(sum - k) != sum_to_count.end())
    {
      ans += sum_to_count[sum - k];
    }

    sum_to_count[sum] += 1;
  }

  return ans;
}

int main() {
  std::vector<int> nums = {23, 2, 4, 6, 7};
  int k = 6;

  std::cout << subarraySum(nums, k);
}