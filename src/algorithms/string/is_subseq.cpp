#include <string>
#include <algorithm>

bool isSubsequence(std::string s, std::string t)
{
  auto s_it = s.begin();
  auto t_it = t.begin();

  while(t_it != t.end())
  {
    if (s_it != s.end() && *s_it == *t_it)
    {
      ++s_it;
    }
    ++t_it;
  }

  return s_it == s.end();
}

int main() {
  std::string s = "acb";
  std::string t = "ahbgdc";

  auto fl = isSubsequence(s, t);
}