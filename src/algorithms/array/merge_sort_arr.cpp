#include <vector>
#include <string>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
  int first_last_idx = m - 1, second_last_idx = n - 1;
  size_t nums1_s = nums1.size();
  int end_idx = nums1_s - 1;


  while(second_last_idx >= 0)
  {
    if (first_last_idx >= 0 && nums1[first_last_idx] > nums2[second_last_idx])
    {
      nums1[end_idx] = nums1[first_last_idx];
      --first_last_idx;
    }
    else
    {
      nums1[end_idx] = nums2[second_last_idx];
      --second_last_idx;
    }
    --end_idx;
  }
}

int main() {
  std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  int m = 3;
  std::vector<int> nums2 = {2, 5, 6};
  int n = 3;
}