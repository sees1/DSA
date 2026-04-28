#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

bool checkInclusion(std::string& s1, std::string& s2)
{
  std::unordered_map<char, int> s1Freq;
  std::unordered_map<char, int> s2Freq;

  size_t s1_s = s1.size();
  size_t s2_s = s2.size();

  if (s2_s < s1_s)
    return false;

  for(size_t idx = 0; idx < s1_s; ++idx)
  {
    s1Freq[s1[idx]]++;
    s2Freq[s2[idx]]++;
  }

  if (s1Freq == s2Freq)
    return true;

  size_t left_idx = 0;
  for(size_t right_idx = s1_s; right_idx < s2_s; ++right_idx)
  {
    s2Freq[s2[right_idx]]++;
    s2Freq[s2[left_idx]]--;

    if (s2Freq[s2[left_idx]] == 0)
      s2Freq.erase(s2[left_idx]);

    left_idx++;

    if (s1Freq == s2Freq)
      return true;
  }

  return false;
}

int main() {
  std::string s1 = "ab";
  std::string s2 = "eidbaoo";

  auto res = checkInclusion(s1, s2);

  std::cout << res;
}