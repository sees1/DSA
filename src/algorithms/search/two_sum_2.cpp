#include <vector>

std::vector<int> twoSum(std::vector<int>& numbers, int target)
{
  int left = 0;
  int right = numbers.size() - 1;

  std::vector<int> res;

  while(left <= right)
  {
    int sum = numbers[left] + numbers[right];

    if (target == sum)
    {
      res.push_back(left + 1);
      res.push_back(right + 1);
      return res;
    }
    if (sum > target)
      right--;
    else
      left++;
  }

  return res;
}

int main() {
  std::vector<int> numbers = {2, 7, 11, 15};
  int target = 9;

  auto res = twoSum(numbers, target);
}