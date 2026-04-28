#include <unordered_map>
#include <vector>

int longestConsecutive(std::vector<int>& nums) {
  std::unordered_map<int, bool> map;
  for(int i = 0; i<nums.size(); i++){
      map[nums[i]] = true;
  }
  for(int i=0; i<nums.size(); i++){
      if(map.count(nums[i]-1) > 0) {
        map[nums[i]] = false;
      }
  }
  int maxlen = 0;
  for(int i=0; i<nums.size(); i++){
      if(map[nums[i]] == true)
      {
        int j=0;
        int count=0;
        map[nums[i]] = false;
        while(map.count(nums[i]+j) > 0)
        {
            j++;
            count++;
        }
        if(count > maxlen)
            maxlen = count;
      }
  }
  return maxlen;
}

int main() {
  std::vector<int> nums = {100, 4, 200, 1, 3, 2};
  auto res = longestConsecutive(nums);
}