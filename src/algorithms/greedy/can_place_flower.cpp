#include <vector>
#include <string>
#include <algorithm>
#include <gtest/gtest.h>

bool canPlaceFlowers(std::vector<int>& flowerbed, int n)
{
  for(int i = 0; i < flowerbed.size(); ++i)
  {
    if ((i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0) && flowerbed[i] == 0)
    {
      flowerbed[i] = 1;
      n--;
    }
  }

  return n <= 0;
}

TEST(DynamicTest, Test1)
{
  std::vector<int> flowerbed = {1, 0, 0, 0, 1};
  EXPECT_EQ(canPlaceFlowers(flowerbed, 1), true);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}