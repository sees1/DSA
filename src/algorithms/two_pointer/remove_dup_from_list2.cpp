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

ListNode* deleteDuplicates(ListNode* head) {
  ListNode* dummy_node = new ListNode(-1);
  dummy_node->next = head;
  ListNode* prev = dummy_node;
  ListNode* curr = head;

  while(curr != nullptr && curr->next != nullptr)
  {
    if (curr->val == curr->next->val)
    {
      while(curr->next && curr->val == curr->next->val)
        curr = curr->next;
      
      prev->next = curr->next;
    }
    else
      prev = prev->next;

    curr = curr->next;
  }

  return head;
}

std::vector<int> toVec(ListNode* head)
{
  std::vector<int> res;

  while(head != nullptr)
  {
    res.push_back(head->val);
    head = head->next;
  }

  return res;
}

TEST(TwoPointer, Test1)
{
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(3);
  head->next->next->next->next = new ListNode(4);
  head->next->next->next->next->next = new ListNode(4);
  head->next->next->next->next->next->next = new ListNode(5);

  ListNode* res = new ListNode(1);
  res->next = new ListNode(2);
  res->next->next = new ListNode(3);
  res->next->next->next = new ListNode(5);
  EXPECT_EQ(toVec(deleteDuplicates(head)), toVec(res));
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}