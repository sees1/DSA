#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

int minMovesToSeat(std::vector<int>& seats, std::vector<int>& students) {
  int acc1 = std::accumulate(seats.begin(), seats.end(), 0);
  int acc2 = std::accumulate(students.begin(), students.end(), 0);

  return std::abs(acc2 - acc1);
}

TEST(DynamicTest, Test1)
{
  std::vector<int> seats = {12,14,19,19,12};
  std::vector<int> students = {19,2,17,20,7};
  EXPECT_EQ(minMovesToSeat(seats, students), 19);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}