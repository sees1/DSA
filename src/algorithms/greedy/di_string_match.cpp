#include <vector>
#include <string>
#include <algorithm>
#include <gtest/gtest.h>

std::vector<int> diStringMatch(std::string s) {
  std::vector<int> res(s.size() + 1);
  int counter = 0;
  for(int i = 0; i < s.size(); ++i)
  {
    if (s[i] == 'I')
    {
      res[i] = counter++;
      if (i == s.size() - 1)
        res[i + 1] = counter++;
    }
  }
  for(int i = s.size() - 1; i >= 0; --i)
  {
    if (s[i] == 'D')
    {
      if (i == s.size() - 1)
        res[i + 1] = counter++;
      res[i] = counter++;
    }
  }

  return res;
}

TEST(DynamicTest, Test1)
{
  std::string s = "IDID";
  std::vector<int> res = {0, 4, 1, 3, 2};
  EXPECT_EQ(diStringMatch(s), res);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}