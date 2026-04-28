#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

int characterReplacement(std::string s, int k)
{
  std::unordered_map<char, int> freq_map;

  size_t left = 0;
  size_t right = 0;
  size_t res = 0;
  int max_freq = 0;
  while(right != s.size())
  {
    freq_map[s[right]]++;
    max_freq = std::max(max_freq, freq_map[s[right]]);

    while((right - left + 1) - max_freq > k)
    {
      freq_map[s[left]]--;
      ++left;
    }
      
    res = std::max(res, right - left + 1);
    ++right;
  }

  return res;
}

int main() {
  std::string s = "KRSCDCSONAJNHLBMDQGIFCPEKPOHQIHLTDIQGEKLRLCQNBOHNDQGHJPNDQPERNFSSSRDEQLFPCCCARFMDLHADJADAGNNSBNCJQOF";
  int k = 4;

  auto res = characterReplacement(s, k);
}