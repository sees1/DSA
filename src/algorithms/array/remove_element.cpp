#include <vector>
#include <algorithm>

int removeElement(std::vector<int>& nums, int val)
{
  // if (nums.size() == 1 && nums[0] == val)
  //   return 0;
  int left = 0;
  int right = nums.size() - 1;

  size_t val_count = 0;

  while(left <= right)
  {
    while (nums[right] == val)
    {
      --right;
      ++val_count;
    }
    if (nums[left] == val && left <= right)
    {
      std::swap(nums[left], nums[right]);
      --right;
      ++val_count;
    }

    ++left;
  }

  return nums.size() - val_count;
}

int main() {
  std::vector<int> nums = {1};

  auto res = removeElement(nums, 1);
}