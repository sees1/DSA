#include <iostream>
#include <vector>
#include <type_traits>
#include <string>
#include <stack>
#include <map>
#include <numeric>
#include <algorithm>

bool isDigit(const std::string& token)
{
  if (token != "+" && 
      token != "-" &&
      token != "*" &&
      token != "/" &&
      token != "(" &&
      token != ")" && 
      token != "*")
    return true;

  return false;
}

bool isDigit(char c)
{
  if (c != '+' && 
      c != '-' &&
      c != '*' &&
      c != '/' &&
      c != '(' &&
      c != ')' && 
      c != '*')
    return true;

  return false;
}

int evalRPN(std::vector<std::string>& tokens)
{
  std::stack<int> s;

  std::for_each(tokens.begin(), tokens.end(), [&s](auto& elem)
  {
    if (isDigit(elem))
    {
      s.push(std::stoi(elem));
    }
    else
    {
      int rhs = s.top();
      s.pop();
      int lhs = s.top();
      s.pop();

      int res;
      if (elem == "+")
      {
        res = lhs + rhs;
      } else if (elem == "-") {
        res = lhs - rhs;
      } else if (elem == "*") {
        res = lhs * rhs;
      } else if (elem == "/") {
        res = lhs / rhs;
      }

      s.push(res);
    }
  });

  return s.top();
}

std::map<char, int> operator_prior = {
  {'(', 0},
  {'+', 1},
  {'-', 1},
  {'*', 2},
  {'/', 2},
  {'^', 3},
  {'~', 4}
};

std::string getStrNum(std::string str, int& pos)
{
  std::string res_num;

  for(; pos < str.size(); ++pos)
  {
    char num = str[pos];

    if(isDigit(num))
      res_num += num;
    else
    {
      pos--;
      break;
    }
  }

  return res_num;
}

std::vector<std::string> toRPN(std::string expr)
{
  std::vector<std::string> rpn;
  std::stack<char> s;

  size_t expr_s = expr.size();

  for(int i = 0; i < expr_s; ++i)
  {
    if (isDigit(expr[i]))
    {
      rpn.push_back(getStrNum(expr, i));
    }
    else if (expr[i] == '(')
    {
      s.push(expr[i]);
    }
    else if (expr[i] == ')')
    {
      while(!s.empty() && s.top() != '(')
      {
        std::string temp(1, s.top());
        rpn.push_back(temp);
        s.pop();
      }
      s.pop();
    }
    else if (operator_prior.count(expr[i]) != 0)
    {
      char op = expr[i];
      if (expr[i] == '-' && (rpn.size() == 0 || operator_prior.count(*(rpn.front().c_str()))))
        op = '~';

      while(!s.empty() && (operator_prior[s.top()] >= operator_prior[op]))
      {
        std::string temp(1, s.top());
        rpn.push_back(temp);
        s.pop();
      }

      s.push(op);
    }
  }

  while(!s.empty())
  {
    std::string temp(1, s.top());
    rpn.push_back(temp);
    s.pop();
  }

  return rpn;
}

int main() {
  std::string expr = "(4+(13/5))";
  std::vector<std::string> tokens = toRPN(expr);

  std::cout << evalRPN(tokens);
}