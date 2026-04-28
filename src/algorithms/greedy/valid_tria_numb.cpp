#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>


int triangleNumber(std::vector<int>& nums) {
  std::sort(nums.begin(), nums.end());

  int ans = 0;
  for(int i = 0; i < nums.size() - 2; ++i)
  {
    for(int j = i + 1; j < nums.size() - 1; ++j)
    {
      int left = j + 1;
      int right = nums.size() - 1;

      while (left <= right)
      {
        int mid = (left + right) / 2;

        if (nums[i] + nums[j] > nums[mid])
        {
          left = mid + 1;
        }
        else
        {
          right = mid - 1;
        }
      }

      ans += (right - j);
    }
  }

  return ans;
}

TEST(DynamicTest, Test1)
{
  std::vector<int> nums = {4, 2, 3, 4};
  EXPECT_EQ(triangleNumber(nums), 4);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}