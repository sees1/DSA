
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
  ListNode* current = new ListNode();
  ListNode* head = current;

  int apendix = 0;

  while(l1 != nullptr || l2 != nullptr)
  {
    current->next = new ListNode();

    int dig1;
    int dig2;

    if (l1 == nullptr)
      dig1 = 0;
    else
    {
      dig1 = l1->val;
      l1 = l1->next;
    }

    if (l2 == nullptr)
      dig2 = 0;
    else
    {
      dig2 = l2->val;
      l2 = l2->next;
    }

    int sum = dig1 + dig2 + apendix;

    if(sum / 10 > 0)
    {
      current = current->next;
      current->val = sum % 10;
      apendix = 1;
    }
    else
    {
      current = current->next;
      current->val = sum;
      apendix = 0;
    }
  }

  if (apendix)
    current->next = new ListNode(1);

  ListNode* temp_head = head;
  head = head->next;
  temp_head = nullptr;
  return head;
}

int main() {
  ListNode* num1 = new ListNode(9);
  num1->next = new ListNode(9);
  num1->next->next = new ListNode(9);
  num1->next->next->next = new ListNode(9);
  num1->next->next->next->next = new ListNode(9);
  num1->next->next->next->next->next = new ListNode(9);
  num1->next->next->next->next->next->next = new ListNode(9);

  ListNode* num2 = new ListNode(9);
  num2->next = new ListNode(9);
  num2->next->next = new ListNode(9);
  num2->next->next->next = new ListNode(9);

  ListNode* num3 = new ListNode(2);
  num3->next = new ListNode(4);
  num3->next->next = new ListNode(3);

  ListNode* num4 = new ListNode(5);
  num4->next = new ListNode(6);
  num4->next->next = new ListNode(4);

  ListNode* res = addTwoNumbers(num1, num2);

}