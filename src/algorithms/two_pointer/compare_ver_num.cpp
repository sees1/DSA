#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <gtest/gtest.h>

int compareVersion(std::string version1, std::string version2) {
    int i = 0, j = 0;
    int n = version1.size(), m = version2.size();

    while (i < n || j < m) {
        long num1 = 0;
        while (i < n && version1[i] != '.') {
            num1 = num1 * 10 + (version1[i] - '0');
            i++;
        }

        long num2 = 0;
        while (j < m && version2[j] != '.') {
            num2 = num2 * 10 + (version2[j] - '0');
            j++;
        }

        if (num1 < num2) return -1;
        if (num1 > num2) return 1;

        i++; // пропускаем '.'
        j++;
    }

    return 0;
}

TEST(TwoPointer, Test1)
{
  std::string v1 = "1.0";
  std::string v2 = "1.0.0.0";
  EXPECT_EQ(compareVersion(v1, v2), 0);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}