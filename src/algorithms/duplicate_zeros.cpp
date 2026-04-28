#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool checkIfExist(vector<int>& arr) {
    vector<int> pow(arr.size());
    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); ++i)
    {
        pow[i] = 2 * arr[i];    
    }
    for(int i = 0; i < arr.size(); ++i)
    {
        int l = 0, r = arr.size() - 1;
        while(l <= r)
        {
            int m = (l + r) / 2; 
            if(arr[i] > pow[m])
            {
                l = m + 1;
            }
            else if(arr[i] < pow[m])
            {
                r = m - 1;
            }
            else
            {
                if(i == m)
                {
                    break;
                }
                return true;
            }
        }
    }
    return false;
}

// bool checkIfExist(vector<int>& arr) {
//     sort(arr.begin(), arr.end());
//     vector<int> pow(arr.size());
//     for(int i = 0; i < arr.size(); ++i)
//     {
//         pow[i] = arr[i] * arr[i];    
//     }
//     if(arr[0] == pow[1])
//     {
//         return true;
//     }
//     if(arr[arr.size() - 1] == pow[arr.size() - 2])
//     {
//         return true;
//     }
//     for(int i = 1; i < arr.size() - 1; ++i)
//     {
//         if(arr[i] == pow[i + 1] || arr[i] == pow[i - 1])
//         {
//             return true;
//         }
//     }
//     return false;
// }

int removeElement(vector<int>& nums, int val) {
    int k = 0;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] != val)
        {
            nums[k++] = nums[i];
        }
    }
    return (nums.size() - k);
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int new_length = m + n;
    vector<int> res(m+n);
    for(int i = 0; i < m + n; ++i)
    {
        if(i <= m)
        {
            res[i] = nums1[i];
        }
        else
        {
            res[i] = nums2[i - m];
        }
    }
    sort(res.begin(), res.end());
    nums1.resize(new_length);
    for(int i = 0; i < new_length; ++i)
    {
        nums1[i] = res[i];
    }
}

void duplicateZeros(vector<int>& arr) {
    int zeros = 0;
    for(int i = 0; i < arr.size(); ++i)
    {
        if(!arr[i])
        {
            ++zeros;
        }
    }
    int old_length = arr.size();
    int new_length = arr.size() + zeros;
    arr.resize(new_length);
    for(int i = old_length - 1, j = new_length - 1; i > 0, j > 0; --i, --j)
    {
        if(arr[i] == 0)
        {
            arr[j] = arr[i];
            --j;
            arr[j] = arr[i];
        }
        else
        {
            arr[j] = arr[i];
        }
    }
    arr.resize(old_length);
}

int thirdMax(vector<int>& nums) {
    vector<int> maximum(3);
    maximum[0] = INT_MIN;
    maximum[1] = INT_MIN;
    maximum[2] = INT_MIN;
    bool end_cycle = false;
    if(nums.size() <= 2)
    {
        return *max_element(nums.begin(), nums.end());
    }
    int curr_max1 = 0;
    int curr_max2 = 0;
    for(int key = 0; key < 3; ++key)
    {
        for(int i = 0; i < nums.size(); ++i)
        {
            switch(key)
            {
                case 0:
                    {
                            maximum[0] = *max_element(nums.begin(), nums.end());
                            end_cycle = true;
                            break;
                    }
                case 1:
                    {
                        if(nums[i] < maximum[0])
                        {
                            curr_max1 = max(curr_max1, nums[i]);
                            maximum[1] = curr_max1;
                        }
                        break;
                    }
                case 2:
                    {
                        if(nums[i] < maximum[1])
                        {
                            curr_max2 = max(curr_max2, nums[i]);
                            maximum[2] = curr_max2;
                        }
                        break;
                    }
            }
            if(end_cycle == true)
            {
                end_cycle = false;
                break;
            }
        }
    }
    if(maximum[2] == INT_MIN)
        return *max_element(maximum.begin(), maximum.end());
    else
        return maximum[2];
}

void reverseString(vector<char>& s) {
    int i = s.size() - 1;
    int j = 0;
    for(i,j; i > j; --i, ++j )
    {
        swap(s[i], s[j]);
    }
}

void pascalTriangle(int row_size)
{
  vector<int> row(row_size + 1);

  int i, j;

  for(i = 1; i <= row_size ; i++)
    row[i] = 0;

  row[0] = 1;

  for(j = 1 ; j <= row_size; j++)
      for(i = j; i >= 1 ; i--)
        row[i] = row[i-1] + row[i];

  for(i = 0; i <= row_size ; i++)
      printf ("%ld ", c[i]);
  return 0;
 }
}

int main()
{
  vector<int> v = {4, 5, 0};
  duplicateZeros(v);

  vector<int> v1 = {1};
  vector<int> v2 = {0};

  merge(v1,1,v2,0);

  vector<int> v3 = {0, 1, 2, 2, 3, 0, 4, 2};
  removeElement(v3, 2);

  vector<int> v4 = {0, 0};
  checkIfExist(v4);

  vector<int> v5 = {-2147483648,1,1};
  thirdMax(v5);

  vector<char> v6 = {'h', 'e', 'l', 'l', 'o'};
  reverseString(v6);
}