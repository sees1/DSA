#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

struct Hash {};
struct SliderWindow {};

template <typename Type = Hash>
int lengthOfLongestSubstring(std::string& s)
{
  std::unordered_map<char, size_t> sub;

  size_t s_s = s.size();
  size_t counter = 0;
  for(size_t idx = 0; idx < s_s; ++idx)
  {
    if(sub.find(s[idx]) == sub.end())
    {
      sub.insert({s[idx], idx});
    }
    else
    {
      counter = std::max(counter, sub.size());
      idx = sub.find(s[idx])->second;
      sub.clear();
    }
  }
  counter = std::max(counter, sub.size());

  return counter;
}

template <>
int lengthOfLongestSubstring<SliderWindow>(std::string& s)
{
  size_t left_idx = 0;
  size_t right_idx = 0;

  size_t s_s = s.size();
  size_t counter = 0;

  std::vector<int> hash(256, -1);
  
  for(right_idx; right_idx < s_s; ++right_idx)
  {
    if (hash[s[right_idx]] != -1)
    {
      if (hash[s[right_idx]] >= left_idx)
      {
        left_idx = hash[s[right_idx]] + 1;
      }
    }

    counter = std::max(counter, right_idx - left_idx + 1);
    hash[s[right_idx]] = right_idx;
  }

  return counter;
}

int main() {
  std::string in = "dvdf";

  std::cout << lengthOfLongestSubstring<SliderWindow>(in);
}