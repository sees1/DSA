#include <vector>
#include <limits>

int findMin(std::vector<int>& nums)
{
  int ans = std::numeric_limits<int>::max();

  int left = 0;
  int right = nums.size() - 1;
  while(left <= right)
  {
    int mid = (left + right) / 2;

    ans = std::min(std::min(ans, nums[mid]), std::min(nums[left], nums[right]));

    if (nums[mid] < nums[right])
      right = mid - 1;
    else
      left = mid + 1;
  }

  return ans;
}

int main() {
  std::vector<int> nums = {3, 4, 5, 1, 2};
  auto res = findMin(nums);
}