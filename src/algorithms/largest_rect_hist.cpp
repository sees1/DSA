#include <stack>
#include <vector>
#include <cmath>

using std::vector;
using std::stack;
using std::max;


class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int ans = 0;
    std::stack<int> stack;
    for (int i = 0; i <= heights.size(); ++i) {
      while (!stack.empty() && (i == heights.size() || heights[stack.top()] > heights[i])) {
        const int h = heights[stack.top()];
        stack.pop();
        const int w = stack.empty() ? i : i - stack.top() - 1;
        ans = max(ans, h * w);
      }
      stack.push(i);
    }
    return ans;
  }

  int largestRectangleAreaV2(vector<int>& heights) {
    stack<std::pair<int, int>> basic_rect;
    int max_area = 0;
    
    for(int i = 0; i < heights.size(); ++i)
    {
      int start = i;
      while(!basic_rect.empty() && basic_rect.top().second > heights[i])
      {
        int h = basic_rect.top().second;
        int index = basic_rect.top().first;
        basic_rect.pop();
        max_area = std::max(max_area, h * (i - index));
        start = index;
      }
      basic_rect.push({start, heights[i]});
    }
    
    while(!basic_rect.empty())
    {
      max_area = std::max(max_area, (basic_rect.top().second * ((int)heights.size() - basic_rect.top().first)));
      basic_rect.pop();
    }
    
    return max_area;
  }
};

int main() {
  std::vector<int> heights = {2,1,5,6,2,3};

  Solution s;
  s.largestRectangleAreaV2(heights);
}