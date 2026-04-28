#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;

void Sort(std::vector<int>& nums, int begin, int end)
{
  if (end - begin < 1)
    return;
  
  auto middle = begin + (end - begin) / 2;
  
  Sort(nums, begin, middle);
  Sort(nums, middle + 1, end);

  auto b = begin;
  auto m = middle + 1;

  vector<int> temp;
  for(int i = 0; i <= end - begin; ++i)
  {
    if (b >= middle + 1 || (m <= end && nums[b] > nums[m]))
    {
      temp.push_back(nums[m]);
      ++m;
    }
    else
    {
      temp.push_back(nums[b]);
      ++b;
    }
  }

  for(int i = begin, counter = 0; i <= end; ++i, ++counter)
  {
    nums[i] = temp[counter];
  }
}

vector<int> sortArray(vector<int>& nums)
{
  Sort(nums, 0, nums.size() - 1);

  return nums;
}

std::ostream& operator<<(std::ostream& v_out, std::vector<int> out)
{
  std::for_each(out.begin(), out.end(),
  [&v_out](auto&& elem)
  {
    v_out << elem;
  });

  return v_out;
}

int main() 
{
  std::vector<int> in = {9, 8, 7, 6, 5};

  std::cout << sortArray(in);
}