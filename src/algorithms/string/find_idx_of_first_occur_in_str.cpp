#include <iostream>
#include <string>

int strStr(std::string haystack, std::string needle)
{
  int left = 0;
  int right = 0;

  int it = 0;

  while(right != haystack.size())
  {
    if (haystack[right] == needle[it] && it == needle.size() - 1)
    {
      return right - it;
    }
    else if (haystack[right] == needle[it] && it != needle.size() - 1)
    {
      ++it;
    }
    else if (haystack[right] != needle[it])
    {
      ++left;
      while(haystack[left] != needle[0] && left < haystack.size())
        ++left;

      right = left;
      it = 0;
      continue;
    }

    ++right;
  }

  return -1;
}

int main () {
  std::string haystack = "leetcode";
  std::string needle = "leeto";

  auto res = strStr(haystack, needle);
}