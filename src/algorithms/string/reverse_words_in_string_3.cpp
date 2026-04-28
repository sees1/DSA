#include <string>
#include <sstream>

std::string reverseWords(std::string s) {
  std::istringstream sstream(s);
  std::string token;
  std::string res;
  while(std::getline(sstream, token, ' '))
  {
      res += std::string(token.rbegin(), token.rend());
      res += " ";
  }

  return std::string(res.begin(), res.end() - 1);
}

int main () {
  std::string s = "Let's take LeetCode contest";
  auto res = reverseWords(s);
}