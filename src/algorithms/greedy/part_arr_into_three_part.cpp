#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <string>
#include <gtest/gtest.h>

bool canThreePartsEqualSum(std::vector<int>& arr)
{
  std::sort(arr.begin(), arr.end());
  int acc = std::accumulate(arr.begin(), arr.end(), 0);

  if (acc % 3 == 0)
  {
    int part_s = acc / 3;
    int part_count = 0;
    int sum = 0;
    for(int i = 0; i < arr.size(); ++i)
    {
      sum += arr[i];
      if (sum == part_s)
      {
        part_count++;
        sum = 0;
      }
    }

    return part_count == 3 ? true : false;
  }

  return false;
}

TEST(DynamicTest, Test1)
{
  std::vector<int> arr = {0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1};
  EXPECT_EQ(canThreePartsEqualSum(arr), true);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}