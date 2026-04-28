#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;

string vecToString(std::vector<int>& v, size_t start_idx, size_t end_idx)
{
  std::string res = std::to_string(v[start_idx]);
  
  if (start_idx != end_idx)
  {
    res += "->";
    res += std::to_string(v[end_idx]);
  }

  return res;
}

vector<string> summaryRanges(vector<int>& nums)
{
  bool is_seq = true;
  size_t nums_s = nums.size();

  std::vector<string> res;

  if (nums.empty())
    return res;

  size_t prev_idx = 0;
  int prev_num = nums[0];

  if (nums.size() == 1)
  {
    res.push_back(std::to_string(prev_num));
    return res;
  }



  for(size_t idx = 1; idx < nums_s; ++idx)
  {
    if (nums[idx] == ++prev_num)
    {
      continue;
    }
    else
    {
      prev_num = nums[idx];
      res.push_back(vecToString(nums, prev_idx, idx - 1));
      prev_idx = idx;
    }
  }

  res.push_back(vecToString(nums, prev_idx, nums.size() - 1));

  return res;
}

int main() {
  vector<int> in = {0, 1, 2, 4, 5, 7, 9};

  auto res = summaryRanges(in);

  std::cout << res[0] << std::endl;
}