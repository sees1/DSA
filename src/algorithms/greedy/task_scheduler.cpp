#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

int leastInterval(std::vector<char>& tasks, int n)
{
  std::unordered_map<char, int> freq_map;
  for(auto& task : tasks)
    freq_map[task]++;

  std::priority_queue<int> pq;
  for(auto& [_, val] : freq_map)
    pq.push(val);

  int time = 0;
  while(!pq.empty())
  {
    int cycle = n + 1;
    std::vector<int> temp;

    while (cycle-- && !pq.empty())
    {
      int p = pq.top();
      pq.pop();
      if (--p > 0)
        temp.push_back(p);
      time++;
    }

    for (auto& p : temp)
      pq.push(p);

    if (!pq.empty())
      time += cycle + 1;
  }

  return time;
}

TEST(DynamicTest, Test1)
{
  std::vector<char> nums = {'A', 'A', 'A', 'B', 'B', 'B'};
  EXPECT_EQ(leastInterval(nums, 2), 8);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}