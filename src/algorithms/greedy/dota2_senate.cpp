#include <vector>
#include <queue>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

std::string predictPartyVictory(std::string senate)
{
  std::queue<int> rad;
  std::queue<int> dir;
  int n = senate.size();
  for(int i = 0; i < n; ++i)
  {
    if (senate[i] == 'R')
      rad.push(i);
    else
      dir.push(i);
  }

  while(!rad.empty() && !dir.empty())
  {
    if (rad.front() < dir.front())
      rad.push(n++);
    else
      dir.push(n++);

    rad.pop();
    dir.pop();
  }

  return rad.empty() ? "Dire" : "Radiant";
}

TEST(DynamicTest, Test1)
{
  std::string s = "DDRRR";
  EXPECT_EQ(predictPartyVictory(s), "Dire");
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}