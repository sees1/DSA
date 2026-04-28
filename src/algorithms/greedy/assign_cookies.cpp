#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

int findContentChildren(std::vector<int>& g, std::vector<int>& s)
{
  std::sort(g.begin(), g.end());
  std::sort(s.begin(), s.end());

  int count = 0;
  std::vector<int>::iterator new_start = s.begin();
  for(auto& child : g)
  {
    new_start = std::lower_bound(new_start, s.end(), child);
    if (new_start == s.end())
      break;
    else
    {
      std::advance(new_start, 1);
      count++;
    }
  }

  return count;
}

TEST(DynamicTest, Test1)
{
  std::vector<int> g = {1, 2};
  std::vector<int> s = {1, 2, 3};
  EXPECT_EQ(findContentChildren(g, s), 2);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}