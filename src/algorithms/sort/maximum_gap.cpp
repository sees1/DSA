#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

void mergeSortHelper(std::vector<int>& nums, std::vector<int>& buffer, int l_idx, int r_idx)
{
  if (l_idx < r_idx)
  {
    int m_idx = (l_idx + r_idx) / 2;
    mergeSortHelper(nums, buffer, l_idx, m_idx);
    mergeSortHelper(nums, buffer, m_idx + 1, r_idx);

    int buff_pos = l_idx;
    int lhs_pos = l_idx;
    int rhs_pos = m_idx + 1;
    while(lhs_pos <= m_idx && rhs_pos <= r_idx)
    {
      if (nums[lhs_pos] < nums[rhs_pos])
        buffer[buff_pos++] = nums[lhs_pos++];
      else
        buffer[buff_pos++] = nums[rhs_pos++];
    }
    while(lhs_pos <= m_idx)
    {
      buffer[buff_pos++] = nums[lhs_pos++];
    }
    while(rhs_pos <= r_idx)
    {
      buffer[buff_pos++] = nums[rhs_pos++];
    }

    for(int i = l_idx; i <= r_idx; ++i)
    {
      nums[i] = buffer[i];
    }
  }
}

void mergeSort(std::vector<int>& nums)
{
  std::vector<int> buffer(nums.size());
  mergeSortHelper(nums, buffer, 0, nums.size() - 1);
}

int maximumGap(std::vector<int>& nums)
{
  mergeSort(nums);

  int max_gap = std::numeric_limits<int>::min();

  for(int i = 1; i < nums.size(); ++i)
    max_gap = std::max(max_gap, nums[i] - nums[i - 1]);

  return max_gap == std::numeric_limits<int>::min() ? 0 : max_gap;
}

TEST(DynamicTest, Test1)
{
  std::vector<int> nums = {3, 6, 9, 1};
  EXPECT_EQ(maximumGap(nums), 3);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}