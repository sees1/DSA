#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <gtest/gtest.h>

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2)
{
  std::sort(nums1.begin(), nums1.end());
  std::sort(nums2.begin(), nums2.end());

  size_t nums1_iter = 0;
  size_t nums2_iter = 0;

  std::set<int> res;

  while(nums1_iter < nums1.size() && nums2_iter < nums2.size())
  {
    if (nums1[nums1_iter] < nums2[nums2_iter])
      ++nums1_iter;
    else
    {
      if(nums1[nums1_iter] == nums2[nums2_iter])
      {
        res.insert(nums1[nums1_iter]);
        ++nums1_iter;
      }

      ++nums2_iter;
    }
  }

  return std::vector<int>(res.begin(), res.end());
}

TEST(TwoPointer, Test1)
{
  std::vector<int> nums1 = {1, 2, 2, 1};
  std::vector<int> nums2 = {2, 2};
  std::vector<int> res = {2};
  EXPECT_EQ(intersection(nums1, nums2), res);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}