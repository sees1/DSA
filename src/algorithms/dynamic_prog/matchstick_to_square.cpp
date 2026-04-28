#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <limits>
#include <gtest/gtest.h>

bool buildSquared(std::vector<int>& sides, std::vector<int>& match, int pos, int ideal_side)
{
  if (pos >= match.size())
    return (sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3]);

  for(int i = 0; i < 4; ++i)
  {
    if(sides[i] + match[pos] > ideal_side)
      continue;
    int j = i;
    while(--j >= 0)
    {
      if (sides[i] == sides[j])
        break;
    }
    if (j != -1)
      continue;
    
    sides[i] += match[pos];
    if (buildSquared(sides, match, pos + 1, ideal_side))
      return true;
    sides[i] -= match[pos];
  }

  return false;
}

bool makesquare(std::vector<int>& matchsticks)
{
  int acc = std::accumulate(matchsticks.begin(), matchsticks.end(), 0);

  for(auto& match : matchsticks)
  {
    if (match > acc / 4)
      return false;
  }

  std::vector<int> sides(4, 0);
  std::sort(matchsticks.begin(), matchsticks.end(), std::greater<int>());
  return buildSquared(sides, matchsticks, 0, acc / 4);
}