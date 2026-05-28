#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

struct clear_tag;

template <typename Tag = void>
std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3)
{
  size_t s1 = 0;
  size_t s2 = 0;
  size_t s3 = 0;

  std::vector<int> res;

  while(s1 < nums1.size() && s2 < nums2.size() && s3 < nums3.size())
  {
    if (nums1[s1] < nums2[s2])
    {
      s1++;
    }
    else
    {
      if (nums1[s1] == nums2[s2])
      {
        if (nums2[s2] < nums3[s3])
        {
          s2++;
        }
        else
        {
          if (nums2[s2] == nums3[s3])
          {
            res.push_back(nums3[s3]);
            s1++;
            s2++;
            s3++;

            while (s1 < nums1.size() && nums1[s1] == nums1[s1 - 1])
                s1++;
            while (s2 < nums2.size() && nums2[s2] == nums2[s2 - 1])
                s2++;
            while (s3 < nums3.size() && nums3[s3] == nums3[s3 - 1])
                s3++;
          }
          else
          {
            s3++;
          }
        }
      }
      else
        s2++;
    }
  }
}

template <typename Tag = void>
std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3)
{
  size_t s1 = 0;
  size_t s2 = 0;
  size_t s3 = 0;

  std::vector<int> res;
  while(s1 < nums1.size() && s2 < nums2.size() && s3 < nums3.size())
  {
    if (nums1[s1] == nums2[s2] && nums2[s2] == nums3[s3])
    {
      res.push_back(nums1[s1]);
      s1++;
      s2++;
      s3++;

      while(s1 < nums1.size() && nums1[s1] == nums1[s1 - 1])
        s1++;
      while(s2 < nums2.size() && nums2[s2] == nums2[s2 - 1])
        s2++;
      while(s3 < nums3.size() && nums3[s3] == nums3[s3 - 1])
        s3++;
    }
    else if (nums1[s1] < nums2[s2])
      s1++;
    else if (nums2[s2] < nums3[s3])
      s2++;
    else
      s3++;
  }

  return res;
}

TEST(TwoPointer, Test1)
{
  std::vector<int> nums1 = {1, 5, 10, 20, 30};
  std::vector<int> nums2 = {5, 13, 15, 20};
  std::vector<int> nums3 = {5, 20};
  std::vector<int> res = {5, 20};
  EXPECT_EQ(intersection(nums1, nums2, nums3), res);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}