#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;

struct Naive {};
struct Efficient {};

template <typename Type = Naive>
vector<int> findClosestElements(vector<int> arr, int k, int x)
{
  std::sort(arr.begin(), arr.end(),
    [&x](auto& lhs, auto& rhs)
    {
      if (std::abs(lhs - x) == std::abs(rhs - x))
        return lhs < rhs;

      return std::abs(lhs - x) < std::abs(rhs - x);
    }
  );

  arr.resize(k);
  std::sort(arr.begin(), arr.end());
  return arr;
}

size_t lowerBound(vector<int>& arr, int x)
{
  size_t left = 0;
  size_t right = arr.size() - 1;
  size_t bound = right;

  // binary search
  while (left <= right)
  {
    size_t mid = left + (right - left) / 2;

    if (arr[mid] >= x)
    {
      bound = mid;
      right = mid - 1;
    }
    else
      left = mid + 1;
  }

  return bound;
}

template<>
vector<int> findClosestElements<Efficient>(vector<int> arr, int k, int x)
{
  size_t highest = lowerBound(arr, x);
  int lowest = static_cast<int>(highest - 1);

  while (k--)
  {
    if (lowest < 0)
    {
      highest++;
      continue;
    }
    if (highest >= arr.size())
    {
      lowest--;
      continue;
    }
    if (std::abs(x - arr[lowest]) > std::abs(x - arr[highest]))
      highest++;
    else
      lowest--;
  }

  return vector<int>(arr.begin() + lowest + 1, arr.begin() + highest);
}

int main()
{
  std::vector<int> in = {1, 2, 3, 4, 5};
  int k = 4;
  int x = 3;

  // auto res = findClosestElements<Naive>(in, k, x);
  auto res2 = findClosestElements<Efficient>(in, k, x);

  std::cout << res2.size();

}