#include <vector>
    
struct naive_tag {};
struct eff_tag {};

void shiftVector(std::vector<int>& nums, int from_id, int to_id, int discr)
{
  while (from_id != to_id + 1)
  {
    std::swap(nums[from_id], nums[from_id + discr]);
    ++from_id;
  }
}

template <typename Tag>
int removeDuplicates(std::vector<int>& nums) { return 0; }

template<>
int removeDuplicates<naive_tag>(std::vector<int>& nums)
{
  int left = 0;
  int right = nums.size() - 1;

  int dup = 0;
  int current_num = nums[left];
  while(left < right)
  {
    if (nums[left] != current_num)
    {
      current_num = nums[left];
      dup = 1;
    }
    else
    {
      ++dup;
    }

    if (dup > 2)
    {
      shiftVector(nums, left + 1, right, -1);
      --dup;
      --right;
    }
    else
      ++left;
  }

  return right + 1;
}

template<>
int removeDuplicates<eff_tag>(std::vector<int>& nums)
{
  if(nums.size() <= 2)
    return nums.size();
  
  int k = 2;
  for(int i = 2;i < nums.size(); i++)
  {
    if(nums[i] != nums[k-2])
    {
      nums[k] = nums[i];
      k++;
    }
  }
  return k;
}

int main() {
  std::vector<int> nums = {1, 1, 1, 2, 2, 3, 3};
  auto res = removeDuplicates<eff_tag>(nums);
}