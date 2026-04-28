#include <vector>
#include <stack>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

std::string removeKdigits(std::string num, int k)
{
  std::stack<char> st;

  for(int i = 0; i < num.size(); ++i)
  {
    while(!st.empty() && k != 0 && num[i] < st.top())
    {
      k--;
      st.pop();
    }

    st.push(num[i]);

    if(st.size() == 1 && num[i] == '0')
      st.pop();
  }

  while (k != 0 && !st.empty())
  {
    k--;
    st.pop();
  }

  std::string res;
  while(!st.empty())
  {
    res.push_back(st.top());
    st.pop();
  }

  std::reverse(res.begin(), res.end());
  
  if(res.empty())
    return "0";
  else
    return res;
}

TEST(DynamicTest, Test1)
{
  std::string num = "1432219";
  EXPECT_EQ(removeKdigits(num, 3), "1219");
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}