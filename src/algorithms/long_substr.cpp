#include <string>
#include <algorithm>
#include <unordered_set>
#include <tuple>
#include <set>
#include <iostream>
#include <vector>
#include <numeric>
#include <regex>
#include <limits>
#include <cmath>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
      int n = s.length();
      int maxLength = 0;
      std::unordered_set<char> charSet;
      int left = 0;
      
      for (int right = 0; right < n; right++) {
          if (charSet.count(s[right]) == 0) {
              charSet.insert(s[right]);
              maxLength = std::max(maxLength, right - left + 1);
          } else {
              while (charSet.count(s[right])) {
                  charSet.erase(s[left]);
                  left++;
              }
              charSet.insert(s[right]);
          }
      }
      
      return maxLength;
  }

  std::string longestPalindrome(std::string s) {
      if (s.length() <= 1) {
          return s;
      }
      
      int maxLen = 1;
      std::string maxStr = s.substr(0, 1);
      s = "#" + std::regex_replace(s, std::regex(""), "#") + "#";
      std::vector<int> dp(s.length(), 0);
      int center = 0;
      int right = 0;
      
      for (int i = 0; i < s.length(); ++i) {
          if (i < right) {
              dp[i] = std::min(right - i, dp[2 * center - i]);
          }
          
          while (i - dp[i] - 1 >= 0 && i + dp[i] + 1 < s.length() && s[i - dp[i] - 1] == s[i + dp[i] + 1]) {
              dp[i]++;
          }
          
          if (i + dp[i] > right) {
              center = i;
              right = i + dp[i];
          }
          
          if (dp[i] > maxLen) {
              maxLen = dp[i];
              maxStr = s.substr(i - dp[i], 2 * dp[i] + 1);
              maxStr.erase(std::remove(maxStr.begin(), maxStr.end(), '#'), maxStr.end());
          }
      }
      
      return maxStr;
  }

  std::string convert(std::string s, int numRows) {
    size_t pos = 0;
    size_t cur = 0;
    bool go_down = true;

    std::vector<std::string> rows(numRows,"");

    while(cur != s.size())
    {
      if(pos == 0)
        go_down = true;
      else if(pos == numRows - 1)
        go_down = false;

      rows[pos] += s[cur];

      if(go_down)
        pos++;
      else
        pos--;

      cur++;
    }

    std::string sum;
    std::for_each(rows.begin(), rows.end(),[&sum](auto& item){ sum += item;});

    return sum;
  }

  int reverse(int x) {
    int temp_x = x;
    if(x < 0)
      temp_x = -temp_x;

    std::string s;

    if (x < 10 && x > -10)
      return x;

    while(temp_x != 0)
    {
      s += ('0' + (temp_x % 10));
      temp_x = temp_x / 10;
    }
    // else if(x < 0)
    //  s.insert(0, 1, '-');

    int multip = 1;

    int res = 0;

    for(int i = s.size() - 1; i >= 0; --i)
    {
      res += (s[i] - '0') * multip;
      multip *= 10;
    }

    if(x < 0)
      res = -res;

    return res;
  }

  int maxArea(std::vector<int>&& height) {
    int left = 0;
    int right = height.size() - 1;
    int max_area = 0;
    int area = 0;
    int min_height = 0;

    while(left < right)
    {
      min_height = std::min(height[left], height[right]);
      area = (right - left) * (min_height);

      if(area > max_area)
        max_area = area;
      
      if(height[left] > height[right])
        right--;
      else
        left++;
    }

    return max_area;
  }

  std::vector<std::vector<int>> threeSum(std::vector<int>&& nums) {
      std::vector<std::vector<int>> res;
      sort(nums.begin(), nums.end());

      for (int i = 0; i < nums.size(); i++) {
          if (i > 0 && nums[i] == nums[i-1]) {
              continue;
          }
          
          int j = i + 1;
          int k = nums.size() - 1;

          while (j < k) {
              int total = nums[i] + nums[j] + nums[k];

              if (total > 0) {
                  k--;
              } else if (total < 0) {
                  j++;
              } else {
                  res.push_back({nums[i], nums[j], nums[k]});
                  j++;

                  while (nums[j] == nums[j-1] && j < k) {
                      j++;
                  }
              }
          }
      }
      return res;        
  }

  int threeSumClosest(std::vector<int>&& nums, int target) {
    int closest = nums[0] + nums[1] + nums[2];
    std::sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size() - 2; ++i)
    {
      if(i > 0 && nums[i] == nums[i-1])
        continue;

      int left = i + 1;
      int right = nums.size() - 1;

      while(left < right)
      {
        int total = nums[i] + nums[left] + nums[right];

        if(std::abs(total - target) < std::abs(closest - target))
          closest = total;

        if (total == target)
          return total;
        
        if(total < target)
          left++;
        else
          right--;
      }
    }

    return closest;
  }

  std::vector<std::string> letterCombination(std::string digit)
  {
    std::vector<std::string> ans;
    if (digit.length() == 0)
      return ans;
    
    int i = 0;
    std::string output;
    std::string mapping[10] = {"",    "",    "abc",  "def", "ghi",
                               "jkl", "mno", "pqrs", "tuv", "wxyz"};

    letterCombinationHelper(digit, output, i, ans, mapping);
    return ans;
  }

  std::vector<std::vector<int>> fourSum(std::vector<int>&& nums, int target)
  {
    std::vector<std::vector<int>> temp;
    std::sort(nums.begin(), nums.end());

    int nums_s = nums.size();

    for(int i = 0; i < nums_s - 3; ++i)
    {
      if (i > 0 && nums[i] == nums[i-1]) {
        continue;
      }

      for(int left = i + 1; left < nums_s - 2; ++left)
      {
        int middle = left + 1;
        int right = nums_s - 1;

        if(left > 1 && nums[left] == nums[left - 1] && left - 1 != i)
          continue;
        else if(right < nums.size() - 1 && nums[right] == nums[right + 1] )
          continue;

        while(middle < right)
        {
          int total = nums[i] + nums[left] + nums[right] + nums[middle];
          if(total == target && ((nums[middle] == nums[middle - 1] && middle - 1 == left) ||
                                 (nums[middle] != nums[middle - 1])))
          {
            temp.push_back({nums[i], nums[left], nums[right], nums[middle]});
            middle++;
          }
          else if (total < target)
            middle++;
          else if (total > target)
          {
            right--;
          }
          else
          {
            middle++;
          }
        }
      }
    }

    return temp;
  }

  std::vector<std::string> generateParenthesis(int n)
  {
    std::vector<std::string> res;
    std::string s;
    dfs(0, 0, s, res, n);
    return res;
  }

  int divide(int dividend, int divisor)
  {
    bool sign = (divisor < 0) ^ (dividend < 0);
    uint divisor_u = std::abs((long long)divisor);
    uint dividend_u = std::abs((long long)dividend);
    uint temp = divisor_u;
    std::vector<int> ans;
    int counter = 0;
    while(temp <= dividend_u)
    {
      temp = temp << 1;
      if(temp < dividend_u)
        counter++;
      else
      {
        dividend_u -= temp >> 1;
        temp = divisor_u;
        ans.push_back(std::pow(2, counter));
        counter = 0;
      }
    }

    uint res = std::accumulate(ans.begin(), ans.end(), 0);
    if(sign)
    {
      if(res > std::numeric_limits<int>::max())
        return std::numeric_limits<int>::min();
      else
        return res;
    }
    else
    {
      if(res > std::numeric_limits<int>::max())
        return std::numeric_limits<int>::max();
      else
        return res;
    }
  }

  // void nextPermutation(std::vector<int>& nums) {
      
  // }

private:
  void dfs(int open, int close, std::string& s, std::vector<std::string>& temp, int n)
  {
    if(open == close && open + close == n * 2)
    {
      temp.push_back(s);
      return;
    }

    if(open < n)
      dfs(open + 1, close, s += '(', temp, n);
    
    if(close < open)
      dfs(open, close + 1, s += ')', temp, n);
  }

   void letterCombinationHelper(std::string digit,
                               std::string output,
                               int i,
                               std::vector<std::string>& ans,
                               std::string* mapping)
  {
    if(i >= digit.size())
    {
      ans.push_back(output);
      return;
    }

    int num = digit[i] - '0';
    std::string value = mapping[num];

    for (int j = 0; j < value.size(); ++j)
    {
      output += value[j];
      letterCombinationHelper(digit, output, i + 1, ans, mapping);
      output.resize(output.size() - 1);
    }
  }

};

int main(){
  Solution s;
  std::vector<int> b{1, 2, 3};
  int r;
  // return s.lengthOfLongestSubstring("abcabcbb");
  // std::cout << s.longestPalindrome("d");
  // std::cout << s.longestPalindrome("babad");
  // std::cout << s.convert("PAYPALISHIRING", 3);?
  // std::cout << s.reverse(-123);?
  // std::cout << s.maxArea({1,8,6,2,5,4,8,3,7});
  // b = s.threeSum({-4, -2, -2, 0, 4, 5});
  // s.threeSumClosest({-1,2,1,-4}, 1);
  // s.letterCombination("32");
  // s.fourSum({-3,-2,-1,0,0,1,2,3}, 0);
  // b.erase(b.begin(), std::next(b.begin(), 4));
  // s.divide(-2147483648, -1);
  return 0;
}