#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
{
  std::unordered_map<std::string, std::vector<std::string>> m;

  for(auto& s : strs)
  {
    std::string key = s;
    sort(key.begin(), key.end());
    m[key].push_back(s);
  }

  std::vector<std::vector<std::string>> res;
  for(auto& elem : m)
  {
    res.push_back(elem.second);
  }

  return res;
}

int main() {
  std::vector<std::string> in = {"eat", "tea", "tan", "ate", "nat", "bat"};

  auto res = groupAnagrams(in);
}