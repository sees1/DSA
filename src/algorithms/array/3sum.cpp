#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

struct noeff_tag {};
struct eff_tag {};

std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
{
  std::sort(nums.begin(), nums.end());

  std::vector<std::vector<int>> res;

  for(int i = 0; i < nums.size(); ++i)
  {
    if (i > 0 && nums[i] == nums[i - 1])
      continue;
      
    int search = nums[i];

    int left = i + 1;
    int right = nums.size() - 1;

    while(left < right)
    {
      int total = search + nums[left] + nums[right];

      if (total > 0)
        --right;
      else if (total < 0)
        ++left;
      else
      {
        res.push_back({search, nums[right], nums[left]});
        ++left;

        while(nums[left] == nums[left - 1] && left < right)
          ++left;
      }
    }
  }

  return res;
}

int main() {
  std::vector<int> nums = {-2,0,1,1,2};

  auto res = threeSum(nums);
}