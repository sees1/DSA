#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

std::string largestOddNumber(std::string num) {
  size_t last_i = 0;
  for(int i = num.size() - 1; i >= 0; --i)
  {
    if ((num[i] - '0') % 2 != 0)
    {
      last_i = i;
      break;
    }
  }

  return num.substr(0, last_i + 1);
}

TEST(DynamicTest, Test1)
{
  std::string num = "52";
  EXPECT_EQ(largestOddNumber(num), "5");
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}