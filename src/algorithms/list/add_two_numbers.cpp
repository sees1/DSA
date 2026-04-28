#include <string>
#include <vector>

struct ListNode
{
  ListNode(int v, ListNode* n)
  {
    val = v;
    next = n;
  }

public:
  ListNode* next;
  int val;
};

ListNode* reverseList(ListNode* head)
{
  if(head == nullptr || head->next == nullptr)
    return head;
  
  ListNode* temp = head->next;
  ListNode* new_head = reverseList(temp);
  temp->next = head;
  head->next = nullptr;
  return new_head;
}

ListNode* sum(ListNode* first, ListNode* second)
{
  ListNode* head = nullptr;
  ListNode* new_head = nullptr;

  bool plus_one = false;

  while(first != nullptr && second != nullptr)
  {
    int sum = first->val + second->val;

    if(plus_one)
      sum++;

    if(sum > 9)
    {
      int ost = sum % 10;
      new_head = new ListNode(ost, head);
      head = new_head;
      plus_one = true;
    }
    else
    {
      new_head = new ListNode(sum, head);
      head = new_head;
      plus_one = false;
    }

    first = first->next;
    second = second->next;
  }

  if(first == nullptr && second != nullptr)
  {
    while(second != nullptr)
    {
      int sum = second->val;

      if(plus_one)
        sum++;

      if(sum > 9)
      {
        int ost = sum % 10;
        new_head = new ListNode(ost, head);
        head = new_head;
        plus_one = true;
      }
      else
      {
        new_head = new ListNode(sum, head);
        head = new_head;
        plus_one = false;
      }

      second = second->next;
    }

    if(plus_one == true)
    {
      new_head = new ListNode(1, head);
      head = new_head;
      return head;
    }
    else
    {
      return new_head;
    }
  }
  else if(first != nullptr && second == nullptr)
  {
    while(first != nullptr)
    {
      int sum = first->val;

      if(plus_one)
        sum++;

      if(sum > 9)
      {
        int ost = sum % 10;
        new_head = new ListNode(ost, head);
        head = new_head;
        plus_one = true;
      }
      else
      {
        new_head = new ListNode(sum, head);
        head = new_head;
        plus_one = false;
      }
      
      first = first->next;
    }

    if(plus_one == true)
    {
      new_head = new ListNode(1, head);
      head = new_head;
      return head;
    }
    else
    {
      return new_head;
    }
  }
  else
  {
    if(plus_one == true)
    {
      new_head = new ListNode(1, head);
      head = new_head;
      return head;
    }
    else
      return new_head;
  }
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  return sum(l1, l2);
}

int main()
{
  ListNode* head = new ListNode(9, nullptr);

  ListNode* second_head = new ListNode(1, nullptr);
  ListNode* second_second = new ListNode(9, nullptr);
  ListNode* second_third = new ListNode(9, nullptr);

  second_head->next = second_second;
  second_second->next = second_third;

  addTwoNumbers(head, second_head);
}