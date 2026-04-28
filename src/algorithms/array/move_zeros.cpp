#include <vector>
#include <iostream>

size_t findNonZeroIdx(std::vector<int>& nums, size_t prev_idx)
{
  while(nums[prev_idx] == 0 && prev_idx < nums.size() - 1)
  {
    prev_idx++;
  }

  return prev_idx;
}

size_t findZeroIdx(std::vector<int>& nums, size_t prev_idx)
{
  while(nums[prev_idx] != 0 && prev_idx < nums.size() - 1)
  {
    prev_idx++;
  }

  return prev_idx;
}

void moveZeroes(std::vector<int>& nums)
{
  size_t nums_s = nums.size();

  

  size_t left_idx = findZeroIdx(nums, 0);
  size_t right_idx = findNonZeroIdx(nums, 0);
  while(left_idx >= right_idx)
    right_idx = findNonZeroIdx(nums, right_idx);

  while(right_idx != nums_s - 1 && left_idx != nums_s - 1)
  {
    std::swap(nums[left_idx], nums[right_idx]);

    left_idx = findZeroIdx(nums, left_idx);
    right_idx = findNonZeroIdx(nums, right_idx);
  }

  if (left_idx <= right_idx)
    std::swap(nums[left_idx], nums[right_idx]);
}

int main() {
  std::vector<int> in = {1, 0, 0};
  std::vector<int> in2 = {1, 0};

  moveZeroes(in2);

  std::cout << in[0];
}