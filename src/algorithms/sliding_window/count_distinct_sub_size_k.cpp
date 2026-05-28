#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <map>
#include <algorithm>
#include <gtest/gtest.h>

std::vector<int> countDistinct(const std::vector<int>& arr, int k)
{
  std::vector<int> res;
  if (arr.size() < k)
    return res;

  std::unordered_map<int, int> s;

  for(int i = 0; i < k; ++i)
  {
    s[arr[i]] += 1;
  }
  
  res.push_back(s.size());

  for(int i = k; i < arr.size(); ++i)
  {
    s[arr[i]] += 1;
    s[arr[i - k]] -= 1;

    if (s[arr[i - k]] != 0)
      s.erase(arr[i - k]);

    res.push_back(s.size());
  }

  return res;
}

TEST(SlidingWindow, Test1)
{
  std::vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
  std::vector<int> res = {3, 4, 4, 3};
  EXPECT_EQ(countDistinct(arr, 4), res);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}