#include <string>
#include <numeric>
#include <limits>
#include <unordered_map>


int minFreq(std::unordered_map<char, int>& s)
{
  int min = std::numeric_limits<int>::max();
  for(auto& pair : s)
  {
    min = std::min(min, pair.second);
  }

  return min;
}

int longestSubstring(std::string s, int k) {
  std::unordered_map<char, int> freq_map;

  for (auto& c : s)
  {
    freq_map[c]++;
  }

  size_t unique_char_count = freq_map.size();
  freq_map.clear();
  
  size_t res = 0;

  for (int curr_unique_char_count = 1; curr_unique_char_count <= unique_char_count; ++curr_unique_char_count)
  {
    size_t left = 0;
    size_t right = 0;

    while(right != s.size())
    {
      freq_map[s[right]]++;

      while (freq_map.size() > curr_unique_char_count)
      {
        // move left
        freq_map[s[left]]--;
        if (freq_map[s[left]] == 0)
          freq_map.erase(s[left]);
        left++;
      }
      
      if (minFreq(freq_map) >= k)
        res = std::max(res, right - left + 1);

      ++right;
    }

    freq_map.clear();
  }

  return res;
}

int main() {
  std::string s = "ababbcaa";
  int k = 2;
  auto res = longestSubstring(s, k);
}