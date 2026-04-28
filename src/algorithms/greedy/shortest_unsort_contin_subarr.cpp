#include <vector>
#include <stack>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

int findUnsortedSubarray(std::vector<int>& nums)
{
  int left = std::numeric_limits<int>::max();
  int right = std::numeric_limits<int>::min();

  std::stack<int> st;
  for(int i = 0; i < nums.size(); ++i)
  {
    while(!st.empty() && nums[i] < nums[st.top()])
    {
      left = std::min(left, nums[i]);
      st.pop();
    }

    st.push(i);
  }

  st = std::stack<int>();
  for(int i = nums.size() - 1; i >= 0; --i)
  {
    while(!st.empty() && nums[i] > nums[st.top()])
    {
      right = std::max(right, nums[i]);
      st.pop();
    }

    st.push(i);
  }

  if (left == std::numeric_limits<int>::max())
    return 0;
  else
    return (right - left + 1);
}

TEST(DynamicTest, Test1)
{
  std::vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
  EXPECT_EQ(findUnsortedSubarray(nums), 5);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}