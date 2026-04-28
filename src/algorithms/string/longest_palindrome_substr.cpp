#include <string>
#include <vector>
#include <numeric>

struct naive_tag {};
struct binary_tag {};
struct manacher_tag {};

int lengthPalindrome(std::string& s, size_t s_size, size_t left_idx, size_t right_idx)
{
  while (left_idx >= 0 && right_idx < s_size && s[left_idx] == s[right_idx])
  {
    --left_idx;
    ++right_idx;
  }

  return right_idx - left_idx - 1;
}

template<typename Tag>
std::string longestPalindrome(std::string s);

template<>
std::string longestPalindrome<naive_tag>(std::string s)
{
  size_t s_size = s.size();

  if (s_size == 0)
    return {};

  size_t start_idx = 0, end_idx = 0;

  for(size_t idx = 0; idx < s_size; ++idx)
  {
    int odd = lengthPalindrome(s, s_size, idx, idx);
    int even = lengthPalindrome(s, s_size, idx, idx + 1);

    int max_length = std::max(odd, even);

    if (max_length > end_idx - start_idx)
    {
      start_idx = idx - (max_length - 1) / 2;
      end_idx = idx + (max_length) / 2;
    }
  }

  return s.substr(start_idx, end_idx - start_idx + 1);
}

template<>
std::string longestPalindrome<binary_tag>(std::string s)
{

}

int main() {
  std::string s = "babad";

}