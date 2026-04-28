#include <string>
#include <map>
#include <vector>
#include <algorithm>

std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k)
{
  std::map<std::string, int> freq_map;
  std::vector<std::pair<std::string, int>> freq_vec;

  for(auto& str : words)
  {
    freq_map[str]++;
  }

  for(auto& pair : freq_map)
  {
    freq_vec.push_back(pair);
  }

  std::sort(freq_vec.begin(), freq_vec.end(), [](auto& lhs, auto& rhs)
  {
    if (lhs.second == rhs.second)
      return lhs.first < rhs.first;
    else
      return lhs.second > rhs.second;
  });

  std::vector<std::string> res;
  std::transform(freq_vec.begin(), freq_vec.begin() + k, std::back_inserter(res), [](auto& pair) mutable
  {
    return pair.first;
  });

  return res;
}

int main() {
  std::vector<std::string> words = {"i","love","leetcode","i","love","coding"};
  int k = 2;
  auto res = topKFrequent(words, k);
}