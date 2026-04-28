#include <string>
#include <iostream>

bool isPalindrome(std::string& s)
{
  std::string clean_s;

  size_t s_s = s.size();

  for(size_t idx = 0; idx < s_s; ++idx)
  {
    if (s[idx] >= 'A' && s[idx] <= 'Z')
    {
      clean_s.push_back(static_cast<char>('a' + (s[idx] - 'A')));
    }
    else if (s[idx] >= 'a' && s[idx] <= 'z')
    {
      clean_s.push_back(s[idx]);
    }
    else if (s[idx] >= '0' && s[idx] <= '9')
    {
      clean_s.push_back(s[idx]);
    }
  }

  size_t clean_s_s = clean_s.size();

  for(size_t left_idx = 0, right_idx = clean_s_s - 1 ; left_idx < clean_s_s; ++left_idx, --right_idx)
  {
    if (clean_s[left_idx] != clean_s[right_idx])
      return false;
  }

  return true;
}

int main() {
  std::string s = "A man, a plan, a canal: Panama";
  std::string s1 = "0P";

  std::cout << isPalindrome(s1);
}