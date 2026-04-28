#include <vector>
#include <unordered_set>

struct maybe_eff_tag {};
struct eff_tag {};

template<typename Tag>
std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2) { 
  std::vector<std::vector<int>> res;
  return res;
}

template<>
std::vector<std::vector<int>> findDifference<maybe_eff_tag>(std::vector<int>& nums1, std::vector<int>& nums2)
{
  int n1_iter = 0;
  int n2_iter = 0;

  std::vector<std::vector<int>> res(2, std::vector<int>());
  while(n1_iter < nums1.size() && n2_iter < nums2.size())
  {
    if (nums1[n1_iter] < nums2[n2_iter])
    {
      res[0].push_back(nums1[n1_iter]);
      n1_iter++;
    }
    else
    {
      int dup_num;
      while(nums1[n1_iter] == nums2[n2_iter])
      {
        dup_num = nums1[n1_iter];
        n2_iter++;
      }

      while(nums1[n1_iter] == dup_num)
      {
        n1_iter++;
      }

      
      res[1].push_back(nums2[n2_iter]);
      n2_iter++;
    }
  }

  if(n1_iter == nums1.size() && n2_iter != nums2.size())
  {
    if (nums2.size() - n2_iter <= 2)
    {
      while(n2_iter != nums2.size())
      {
        res[1].push_back(nums2[n2_iter++]);
      }
    }
    else
    {
      ++n2_iter;
      if (n2_iter >= nums2.size())
      {
        res[1].push_back(nums2[n2_iter]);
      }
      else
      {
        res[1].push_back(nums2[n2_iter]);
        int k = n2_iter;
        for(; n2_iter < nums2.size(); ++n2_iter)
        {
          if(nums2[n2_iter] != nums2[k - 1])
          {
            nums2[n2_iter] = nums2[k];
            res[1].push_back(nums2[n2_iter]);
            k++;
          }
        }
      }
    }
  }
  else if(n1_iter != nums1.size() && n2_iter == nums2.size())
  {
    if (nums1.size() - n1_iter <= 2)
    {
      while(n1_iter != nums1.size())
      {
        res[0].push_back(nums1[n1_iter++]);
      }
    }
    else
    {
      ++n1_iter;
      if (n1_iter >= nums1.size())
      {
        res[0].push_back(nums1[n1_iter]);
      }
      else
      {
        res[0].push_back(nums1[n1_iter]);
        int k = n1_iter;
        for(; n1_iter < nums1.size(); ++n1_iter)
        {
          if(nums1[n1_iter] != nums1[k - 1])
          {
            nums1[n1_iter] = nums1[k];
            res[0].push_back(nums1[n1_iter]);
            k++;
          }
        }
      }
    }
  }

  return res;
}

template<>
std::vector<std::vector<int>> findDifference<eff_tag>(std::vector<int>& nums1, std::vector<int>& nums2)
{
  std::unordered_set<int> nums1_set(nums1.begin(), nums1.end());
  std::unordered_set<int> nums2_set(nums2.begin(), nums2.end());

  std::vector<std::vector<int>> res(2, std::vector<int>());

  for(auto& el : nums2_set)
  {
    if(nums1_set.count(el) == 0)
    {
      res[1].push_back(el);
    }
  }

  for(auto& el : nums1_set)
  {
    if(nums2_set.count(el) == 0)
    {
      res[0].push_back(el);
    }
  }

  return res;
}


int main() {
  std::vector<int> nums1 = {1, 2, 3, 3};
  std::vector<int> nums2 = {1, 1, 2, 2};

  auto res = findDifference<eff_tag>(nums1, nums2);
}