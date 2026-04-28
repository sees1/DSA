#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
  size_t nums_s = nums.size();
  std::vector<std::pair<int, int>> nums_with_ind(nums_s);
  
  for(size_t idx = 0; idx < nums_s; ++idx)
    nums_with_ind[idx] = {nums[idx], idx};

  std::sort(nums_with_ind.begin(), nums_with_ind.end());

  for(size_t idx = 0; idx < nums_s; ++idx)
  {
    int first = nums_with_ind[idx].first;
    for(size_t jdx = idx + 1; jdx < nums_s; ++jdx)
    {
      int second = nums_with_ind[jdx].first;

      if (first + second == target)
      {
        return std::vector<int>{nums_with_ind[idx].second, nums_with_ind[jdx].second};
      }
      else if (first + second > target)
      {
        break;
      }
    }
  }
}

int main() {
  std::vector<int> in = {2, 7, 11, 15};
  int target = 9;

  auto res = twoSum(in, target);
}