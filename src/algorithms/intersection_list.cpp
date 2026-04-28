struct ListNode
{
  ListNode* next;
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  if(headA == nullptr || headB == nullptr)
    return nullptr;
  
  ListNode* iterA = headA;
  ListNode* iterB = headB;
      

  while (iterA != iterB) {
    iterA = (iterA == nullptr) ? headB : iterA->next;
    iterB = (iterB == nullptr) ? headA : iterB->next;
  }
  
  return iterA;
}

int main()
{
  ListNode* headA = new ListNode();
  ListNode* secondA = new ListNode();
  ListNode* thirdA = new ListNode();

  ListNode* headB = new ListNode();
  ListNode* secondB = new ListNode();

  headA->next = secondA;
  secondA->next = thirdA;

  headB->next = secondB;

  getIntersectionNode(headA, headB);
}