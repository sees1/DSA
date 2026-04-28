#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <numeric>
#include <limits>
#include <gtest/gtest.h>

bool isDigit(char c)
{
  if (c != '+' && 
      c != '-' &&
      c != '*')
    return true;

  return false;
}

std::vector<int> solve(std::string expr, std::unordered_map<std::string, std::vector<int>>& dp)
{
  std::vector<int> res;

  if (dp.count(expr) != 0)
    return dp[expr];

  for(int root = 0; root < expr.size(); ++root)
  {
    if(!isDigit(expr[root]))
    {
      std::vector<int> left = solve(expr.substr(0, root), dp);
      std::vector<int> right = solve(expr.substr(root + 1), dp);

      for(auto& left_n : left)
      {
        for(auto& right_n : right)
        {
          if (expr[root] == '+')
            res.push_back(left_n + right_n);
          else if (expr[root] == '-') 
            res.push_back(left_n - right_n);
          else if (expr[root] == '*')
            res.push_back(left_n * right_n);
        }
      }
    }
  }

  // check only one num
  if (res.empty())
    res.push_back(std::stoi(expr));

  return dp[expr] = res;
}

std::vector<int> diffWaysToCompute(std::string expr)
{
  std::unordered_map<std::string, std::vector<int>> dp;
  return solve(expr, dp);
}

TEST(DynamicTest, Test1)
{
  std::string expr = "2-1-1";
  std::vector<int> res = {2, 0};
  EXPECT_EQ(diffWaysToCompute(expr), res);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}