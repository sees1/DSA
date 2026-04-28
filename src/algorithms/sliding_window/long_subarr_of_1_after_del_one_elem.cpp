#include <vector>
#include <iostream>

using std::vector;

int longestSubarray(vector<int>& nums)
{
  size_t left_idx = 0;
  size_t first_zero_idx = 0;
  size_t right_idx = 0;

  size_t nums_s = nums.size();

  size_t zero_count = 0;
  size_t result = 0;
  for(right_idx; right_idx < nums_s; ++right_idx)
  {
    if (nums[right_idx] == 0)
    {
      if (zero_count == 1)
      {
        result = std::max(result, right_idx - left_idx - 1);
        left_idx = ++first_zero_idx;
        first_zero_idx = right_idx;
      }
      else
      {
        first_zero_idx = right_idx;
        zero_count++;
      }
    }
  }

  result = std::max(result, nums_s - left_idx - 1);

  return result;
}

int main() {
  std::vector<int> in ={0, 1, 1, 1, 0, 1, 1, 0, 1};
  std::vector<int> in2 = {1, 1, 0, 1};

  std::cout << longestSubarray(in2);
}