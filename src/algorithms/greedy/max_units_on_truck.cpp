#include <vector>
#include <string>
#include <algorithm>
#include <gtest/gtest.h>

int maximumUnits(std::vector<std::vector<int>>& boxTypes, int truckSize) {
  std::sort(boxTypes.begin(), boxTypes.end(), [](auto& lhs, auto& rhs)
  {
    return lhs[1] > rhs[1];
  });

  int units = 0;
  int i = 0;
  while(i < boxTypes.size() && truckSize != 0)
  {
    if (truckSize >= boxTypes[i][0])
    {
      truckSize -= boxTypes[i][0];
      units += boxTypes[i][0] * boxTypes[i][1];
    }
    else
    {
      units += truckSize * boxTypes[i][1];
      truckSize = 0;
    }

    ++i;
  }

  return units;
}

TEST(DynamicTest, Test1)
{
  std::vector<std::vector<int>> nums = {{1, 3}, {2, 2}, {3, 1}};
  int truck_size = 4;
  EXPECT_EQ(maximumUnits(nums, truck_size), 8);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}