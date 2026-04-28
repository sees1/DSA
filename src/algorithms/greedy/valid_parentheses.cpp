#include <string>
#include <vector>
#include <stack>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

struct effic_tag;

bool helper(std::string& s, int idx, std::stack<char>& st)
{
  if (idx >= s.size())
    return st.empty();

  if (s[idx] == ')')
  {
    while(!st.empty() && st.top() != '(')
    {
      st.pop();
    }

    if (st.empty())
      return false;
    else
      st.pop();

    return helper(s, idx + 1, st);
  }
  else if (s[idx] == '(')
  {
    st.push('(');
    return helper(s, idx + 1, st);
  }
  else if (s[idx] == '*')
  {
    std::stack<char> copy = st;
    for(auto& c : {'(', ')'})
    {
      s[idx] = c;
      bool fl = helper(s, idx, st);
      if (fl)
        return true;
      else
        st = copy;
    }

    return helper(s, idx + 1, st);
  }

  return false;
}


template <typename Tag = void>
bool checkValidString(std::string s)
{
  if(s.empty() || s[0] == ')')
    return false;

  std::stack<char> st;
  return helper(s, 0, st);
}

template<>
bool checkValidString<effic_tag>(std::string s)
{
  // open parentheses count range
  int open_min = 0;
  int open_max = 0;
  for (char c : s) {
      if (c == '(')
      {
        open_max++;
        open_min++;
      }
      else if (c == ')')
      {
        open_max--;
        open_min--;
      }
      else if (c == '*')
      {
        open_max++; // if `*` become `(` then openCount++
        open_min--; // if `*` become `)` then openCount--
        // if `*` become `` then nothing happens
        // So openCount will be in new range [cmin-1, cmax+1]
      }

      if (open_max < 0)
        return false; // Currently, don't have enough open parentheses to match close parentheses-> Invalid
                                  // For example: ())(
      open_min = std::max(open_min, 0);   // It's invalid if open parentheses count < 0 that's why cmin can't be negative
  }
  return open_min == 0; // Return true if can found `openCount == 0` in range [cmin, cmax]
}

TEST(DynamicTest, Test1)
{
  std::string s = "(*)";
  EXPECT_EQ(checkValidString(s), true);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}