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

ListNode* insertionSortList(ListNode* head)
{
  ListNode* const start = head;

  while(head != nullptr)
  {
    int buff = head->val;
    ListNode* curr = start;
    while(curr != head)
    {
      if (curr->val > buff)
        std::swap(curr->val, buff);
      
      curr = curr->next;
    }
    std::swap(curr->val, buff);
    head = head->next;
  }

  return start;
}

TEST(DynamicTest, Test1)
{
  ListNode* head = new ListNode(4);
  head->next = new ListNode(2);
  head->next->next = new ListNode(1);
  head->next->next->next = new ListNode(3);

  ListNode* res = insertionSortList(head);
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