#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

std::vector<int> findAnagrams(std::string s, std::string p)
{
  size_t s_size = s.size();
  size_t p_size = p.size();

  std::vector<int> res;

  if (s_size < p_size)
    return res;

  std::unordered_map<char, int> p_map;
  std::unordered_map<char, int> window_map;

  
  for(size_t idx = 0; idx < p_size; ++idx)
  {
    ++p_map[p[idx]];
    ++window_map[s[idx]];
  }

  if (p_map == window_map)
    res.push_back(0);

  for(size_t idx = p_size; idx < s_size; ++idx)
  {
    window_map[s[idx - p_size]]--;
    if (window_map[s[idx - p_size]] == 0)
      window_map.erase(s[idx - p_size]);
    window_map[s[idx]]++;



    if (p_map == window_map)
      res.push_back(idx - p_size + 1);
  }

  return res;
}

int main()
{
  std::string s = "cbaebabacd";
  std::string p = "abc";

  auto res = findAnagrams(s, p);
}