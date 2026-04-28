#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>

#include "data_struct/priority_queue/priority_queue.hpp"

#include <gtest/gtest.h>

// TODO: add here external version of algorithm
// TODO: add here inplace version of algorithm
// TODO: add here stable version of algorithm

template <typename T>
void insertionSort(std::vector<T>& nums)
{
  for(int i = 0; i < nums.size(); ++i)
  {
    int exch = nums[i];
    int j = i;
    while(j > 0 && nums[j - 1] > exch)
    {
      nums[j] = nums[j - 1];
      --j;
    }
    nums[j] = exch;
  }
}

struct ThreeWay;

template <typename Tag = void>
void mergeSortHelper(std::vector<int>& nums, std::vector<int>& buffer, int l_idx, int r_idx)
{
  if (l_idx < r_idx)
  {
    int m_idx = (l_idx + r_idx) / 2;
    mergeSortHelper(nums, buffer, l_idx, m_idx);
    mergeSortHelper(nums, buffer, m_idx + 1, r_idx);

    int buffer_pos = l_idx;
    int lhs_pos = l_idx;
    int rhs_pos = m_idx + 1;
    while(lhs_pos <= m_idx && rhs_pos <= r_idx)
    {
      if (nums[lhs_pos] < nums[rhs_pos])
        buffer[buffer_pos] = nums[lhs_pos++];
      else
        buffer[buffer_pos] = nums[rhs_pos++];

      buffer_pos++;
    }
    while(lhs_pos <= m_idx)
    {
      buffer[buffer_pos++] = nums[lhs_pos]++;
    }
    while(rhs_pos <= r_idx)
    {
      buffer[buffer_pos++] = nums[rhs_pos]++;
    }

    for(int i = l_idx; i < r_idx; ++i)
      nums[i] = buffer[i];
  }
}

template<>
void mergeSortHelper<ThreeWay>(std::vector<int>& nums, std::vector<int>& buffer, int l_idx, int r_idx)
{
  if (l_idx < r_idx)
  {
    int m1_idx = l_idx + (r_idx - l_idx) / 3;
    int m2_idx = l_idx + 2 * (r_idx - l_idx) / 3;
    mergeSortHelper<ThreeWay>(nums, buffer, l_idx, m1_idx);
    mergeSortHelper<ThreeWay>(nums, buffer, m1_idx + 1, m2_idx);
    mergeSortHelper<ThreeWay>(nums, buffer, m2_idx + 1, r_idx);

    int buffer_pos = l_idx;
    int lhs_pos = l_idx;
    int mid_pos = m1_idx + 1;
    int rhs_pos = m2_idx + 1;
    while(lhs_pos <= m1_idx || mid_pos <= m2_idx || rhs_pos <= r_idx)
    {
      int min = std::numeric_limits<int>::max();
      int min_idx = -1;

      if (lhs_pos <= m1_idx && nums[lhs_pos] < min)
      {
        min = nums[lhs_pos];
        min_idx = 0;
      }
      if (mid_pos <= m2_idx && nums[mid_pos] < min)
      {
        min = nums[mid_pos];
        min_idx = 1;
      }
      if (rhs_pos <= r_idx && nums[rhs_pos] < min)
      {
        min = nums[rhs_pos];
        min_idx = 2;
      }

      if (min_idx == 0)
        buffer[buffer_pos] = nums[lhs_pos++];
      else if (min_idx == 1)
        buffer[buffer_pos] = nums[mid_pos++];
      else
        buffer[buffer_pos] = nums[rhs_pos++];

      buffer_pos++;
    }

    for(int i = l_idx; i < r_idx; ++i)
      nums[i] = buffer[i];
  }
}

// O(nlog2n) - bad, good, average; O(n) - additional space
template <typename Tag = void>
void mergeSort(std::vector<int>& nums)
{
  std::vector<int> buffer(nums.size());
  mergeSortHelper(nums, buffer, 0, nums.size() - 1);
}

// O(nlog3n) - bad, good, average; O(n) - additional space
template <>
void mergeSort<ThreeWay>(std::vector<int>& nums)
{
  std::vector<int> buffer(nums.size());
  mergeSortHelper<ThreeWay>(nums, buffer, 0, nums.size() - 1);
}

void bubbleSort(std::vector<int>& nums)
{
  size_t n = nums.size();
  for(int i = 0; i < n - 1; ++i)
  {
    bool sort = true;
    for(int j = 0; j < n - 1 - i; ++j)
    {
      if (nums[j] > nums[j + 1])
      {
        std::swap(nums[j], nums[j + 1]);
        sort = false;
      }
    }

    if (!sort) break;
  }
}

void selectionSort(std::vector<int>& nums)
{
  size_t n = nums.size();

  for(auto it = nums.begin(); it != nums.end() - 1; std::advance(it, 1))
  {
    auto jt = std::min_element(it, nums.end());
    std::swap(*it, *jt);
  }
}

int quickPart(std::vector<int>& nums, int l_idx, int r_idx)
{
  int pivot = nums[r_idx];
  int pos = l_idx;

  for(int i = l_idx; i < r_idx; ++i)
    if (nums[i] < pivot)
      std::swap(nums[i], nums[pos++]);

  std::swap(nums[pos], nums[r_idx]);

  return pos;
}

void quickSortHelper(std::vector<int>& nums, int l_idx, int r_idx)
{
  if (l_idx < r_idx)
  {
    int m_idx = quickPart(nums, l_idx, r_idx);

    quickSortHelper(nums, l_idx, m_idx - 1);
    quickSortHelper(nums, m_idx + 1, r_idx);
  }
}

void quickSort(std::vector<int>& nums)
{
  quickSortHelper(nums, 0, nums.size() - 1);
}

void heapSort(std::vector<int>& nums)
{
  study::priority_queue p(nums);

  int pos = 0;
  while(!p.empty())
  {
    nums[pos++] = p.top();
    p.pop();
  }
}

// O(n^2) - bad, good, average; O(1) - additional space
// use in high cost memory systems
void cycleSort(std::vector<int>& nums)
{
  for(int start = 0; start < nums.size() - 1; ++start)
  {
    int value = nums[start];

    int pos = start;
    for(int idx = start + 1; idx < nums.size(); ++idx)
    {
      if (nums[idx] < value)
        pos++;
    }

    if (pos == start)
      continue;

    while(value == nums[pos])
      ++pos;

    std::swap(value, nums[pos]);

    while(pos != start)
    {
      pos = start;
    
      for(int idx = start + 1; idx < nums.size(); ++idx)
      {
        if (nums[idx] < value)
          pos++;
      }

      while(value == nums[pos])
        ++pos;

      std::swap(value, nums[pos]);
    }
  }
}

// O(n + k) - bad, good, average, where k = max_el(arr); O(k) - additional space
void countSort(std::vector<int>& nums)
{
  auto iter = std::max_element(nums.begin(), nums.end());

  std::vector<int> buff(*iter);
  for(auto& el : nums)
    buff[el]++;

  int pos = 0;
  for(int i = 0; i < buff.size(); ++i)
  {
    for(int j = 0; j < buff[i]; ++j)
      nums[pos++] = i;
  }
}

void countSortHelper(std::vector<int>& nums, size_t nums_s, int exp)
{
  std::vector<int> output(nums.size());

  std::vector<int> buff(10);
  for(auto& el : nums)
    buff[(el / exp) % 10]++;

  // make from buff array prefix array (now buff array hold end(after last) pos for each number)
  for(int i = 1; i < 10; ++i)
    buff[i] += buff[i - 1];

  // to make radix sort stable we should iterate backward;
  for(int i = nums_s - 1; i >= 0; --i)
  {
    output[buff[(nums[i] / exp) % 10] - 1] = nums[i];
    buff[(nums[i] / exp) % 10]--;
  }

  for(int i = 0; i < nums_s; ++i)
    nums[i] = output[i];
}

// O(d * (n + b)) - bad, good, average, where d - max number of digits, n - number of elements, b - base of number system;
// O(n + b) - additional space
void radixSort(std::vector<int>& nums)
{
  auto max = std::max_element(nums.begin(), nums.end());

  int exp = 1;
  while((*max) / exp > 0)
  {
    countSortHelper(nums, nums.size(), exp);
    exp *= 10;
  }
}

void bucketSort(std::vector<float>& nums)
{
  int nums_s = nums.size();

  std::vector<std::vector<float>> buckets(nums_s);

  for(int i = 0; i < nums_s; i++)
  {
    int b = nums_s * nums[i];
    buckets[b].push_back(nums[i]);
  }

  for(auto& v : buckets)
    insertionSort(v);

  int pos = 0;
  for(int i = 0; i < buckets.size(); ++i)
  {
    for(int j = 0; j < buckets[i].size(); ++j)
    {
      nums[pos++] = buckets[i][j];
    }
  }
}

TEST(SortTest, InsertionSort)
{
  std::vector<int> nums = {4, 1, 2, 3};
  insertionSort(nums);
  std::vector<int> res = {1, 2, 3, 4};
  EXPECT_EQ(nums, res);
}

TEST(SortTest, MergeSort)
{
  std::vector<int> nums = {4, 1, 2, 3};
  mergeSort(nums);
  std::vector<int> res = {1, 2, 3, 4};
  EXPECT_EQ(nums, res);
}

TEST(SortTest, MergeSort3Way)
{
  std::vector<int> nums = {4, 1, 2, 3};
  mergeSort<ThreeWay>(nums);
  std::vector<int> res = {1, 2, 3, 4};
  EXPECT_EQ(nums, res);
}

TEST(SortTest, BubbleSort)
{
  std::vector<int> nums = {4, 1, 2, 3};
  bubbleSort(nums);
  std::vector<int> res = {1, 2, 3, 4};
  EXPECT_EQ(nums, res);
}

TEST(SortTest, SelectionSort)
{
  std::vector<int> nums = {4, 1, 2, 3};
  selectionSort(nums);
  std::vector<int> res = {1, 2, 3, 4};
  EXPECT_EQ(nums, res);
}

TEST(SortTest, QuickSort)
{
  std::vector<int> nums = {4, 1, 2, 3};
  quickSort(nums);
  std::vector<int> res = {1, 2, 3, 4};
  EXPECT_EQ(nums, res);
}

TEST(SortTest, HeapSort)
{
  std::vector<int> nums = {4, 1, 2, 3};
  heapSort(nums);
  std::vector<int> res = {1, 2, 3, 4};
  EXPECT_EQ(nums, res);
}

TEST(SortTest, CycleSort)
{
  std::vector<int> nums = {4, 1, 2, 3};
  cycleSort(nums);
  std::vector<int> res = {1, 2, 3, 4};
  EXPECT_EQ(nums, res);
}

TEST(SortTest, CountSort)
{
  std::vector<int> nums = {4, 1, 2, 3};
  countSort(nums);
  std::vector<int> res = {1, 2, 3, 4};
  EXPECT_EQ(nums, res);
}

TEST(SortTest, RadixSort)
{
  std::vector<int> nums = {4, 1, 2, 3};
  radixSort(nums);
  std::vector<int> res = {1, 2, 3, 4};
  EXPECT_EQ(nums, res);
}

TEST(SortTest, BucketSort)
{
  std::vector<float> nums = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
  bucketSort(nums);
  std::vector<float> res = {0.1234, 0.3434, 0.565, 0.656, 0.665, 0.897};
  EXPECT_EQ(nums, res);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}