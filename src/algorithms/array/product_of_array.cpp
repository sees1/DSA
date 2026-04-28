#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
   
std::vector<int> productExceptSelf(std::vector<int>& nums) {
  std::vector<int> prefix = {1};
  std::vector<int> suffix = {1};
  std::vector<int> result;

  std::partial_sum(nums.begin(), nums.end() - 1, std::back_inserter(prefix), std::multiplies<>());
  std::partial_sum(nums.rbegin(), nums.rend() - 1, std::back_inserter(suffix), std::multiplies<>());

  std::transform(prefix.begin(), prefix.end(), suffix.rbegin(), std::back_inserter(result), std::multiplies<>());

  return result;
}

int main() {
  std::vector<int> arr = {1, 2, 3, 4};

  auto res = productExceptSelf(arr);
}