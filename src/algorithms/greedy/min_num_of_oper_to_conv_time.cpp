#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

int fromStr(std::string&& time)
{
  int res = 0;
  int rank = 1;
  for(int i = 0; i < time.size(); ++i)
  {
    res += rank * (time[i] - '0');
    rank *= 10;
  }

  return res;
}
int convertTime(std::string current, std::string correct) {
  current = std::string(current.rbegin(), current.rend());
  correct = std::string(correct.rbegin(), correct.rend());

  int curr_min = fromStr(current.substr(0, 2));
  int curr_hour = fromStr(current.substr(3));
  int corr_min = fromStr(correct.substr(0, 2));
  int corr_hour = fromStr(correct.substr(3));

  curr_min += curr_hour * 60;
  corr_min += corr_hour * 60;
  int diff = corr_min - curr_min;

  int oper = diff / 60;
  diff = diff % 60;
  oper += diff / 15;
  diff = diff % 15;
  oper += diff / 5;
  diff = diff % 5;
  oper += diff / 1;
  diff = diff % 1;
  
  return oper;
}

TEST(DynamicTest, Test1)
{
  std::string current = "02:30";
  std::string correct = "04:35";
  EXPECT_EQ(convertTime(current, correct), 3);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}