#include <vector>
#include <map>
#include <algorithm>

std::vector<std::pair<int, int>> merge(std::vector<std::pair<int, int>>& intervals)
{
  std::sort(intervals.begin(), intervals.end());

  size_t left_idx = 0;
  size_t right_idx = 1;
  int interval_left = intervals[0].first;
  int interval_right = intervals[0].second;
  size_t intervals_s = intervals.size();


  std::vector<std::pair<int, int>> new_intervals;

  for(right_idx; right_idx < intervals_s; ++right_idx)
  {
    if (interval_right >= intervals[right_idx].first)
    {
      interval_right = std::max(interval_right, intervals[right_idx].second);
      continue;
    }
    else
    {
      new_intervals.push_back({interval_left, interval_right});
      interval_right = intervals[right_idx].second;
      interval_left = intervals[right_idx].first;
      left_idx = right_idx;
    }
  }

  new_intervals.push_back({interval_left, interval_right});

  return new_intervals;
}

int main() {
  std::vector<std::pair<int, int>> in(4);

  in[0] = {1, 3};
  in[1] = {2, 6};
  in[2] = {8, 10};
  in[3] = {15, 18};
  // in[4] = {1, 10};

  merge(in);

}