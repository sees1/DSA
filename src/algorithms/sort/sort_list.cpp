#include <vector>
#include <string>
#include <numeric>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void convertList(ListNode* head, std::vector<int>& res)
{
  if (head == nullptr)
    return;

  res.push_back(head->val);
  convertList(head->next, res);
  return;
}

void mergeSortHelper(std::vector<ListNode*>& nums, std::vector<ListNode*>& buffer, int l_idx, int r_idx)
{
  if (l_idx < r_idx)
  {
    int m_idx = (l_idx + r_idx) / 2;
    mergeSortHelper(nums, buffer, l_idx, m_idx);
    mergeSortHelper(nums, buffer, m_idx + 1, r_idx);

    int pos = l_idx;
    for(int lhs_start = l_idx, rhs_start = m_idx + 1; lhs_start <= m_idx || rhs_start <= r_idx;)
    {
      if (rhs_start > r_idx || (lhs_start <= m_idx && nums[lhs_start]->val < nums[rhs_start]->val))
      {
        buffer[pos] = nums[lhs_start];
        lhs_start++;
      }
      else
      {
        buffer[pos] = nums[rhs_start];
        rhs_start++;
      }
      ++pos;
    }

    // back to main vector
    for(int i = l_idx; i <= r_idx; ++i)
    {
      nums[i] = buffer[i];
    }
  }
}

void mergeSort(std::vector<ListNode*>& nums)
{
  std::vector<ListNode*> buffer(nums.size());
  mergeSortHelper(nums, buffer, 0, nums.size() - 1);
}

ListNode* sortList(ListNode* head)
{
  if (head == nullptr)
    return nullptr;

  std::vector<ListNode*> cont;
  while(head != nullptr)
  {
    cont.push_back(head);
    head = head->next;
  }

  mergeSort(cont);

  ListNode* new_head = cont[0];
  ListNode* curr = new_head;
  for(int i = 1; i < cont.size(); ++i)
  {
    curr->next = cont[i];
    curr = cont[i];
  }
  curr->next = nullptr;

  return new_head;
}

TEST(DynamicTest, Test1)
{
  ListNode* head = new ListNode(4);
  head->next = new ListNode(2);
  head->next->next = new ListNode(1);
  head->next->next->next = new ListNode(3);

  ListNode* res = sortList(head);
  std::vector<int> res_vec;
  convertList(res, res_vec);
  std::vector<int> correct = {1, 2, 3, 4};

  EXPECT_EQ(res_vec, correct);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}