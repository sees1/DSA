#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

bool isIsomorphic(string s, string t) {
  vector<int> idx_S(256, 0);
  vector<int> idx_T(256, 0);

  int len = s.length();

  if (len != t.length())
      return false;

  for (int i = 0; i < len; i++) {
      if (idx_S[s[i]] != idx_T[t[i]])
          return false;

      idx_S[s[i]] = i + 1;
      idx_T[t[i]] = i + 1;
  }
  return true;
}

int main() {
  string s1 = "bbbaaaba";
  string s2 = "aaabbbba";

  std::cout << isIsomorphic(s1, s2);
}