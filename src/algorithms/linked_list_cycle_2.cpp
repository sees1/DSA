struct ListNode
{
  ListNode* next;
  int val = 0;
};

ListNode* oddEvenList(ListNode* head) {
    ListNode* f_fast = head;
    ListNode* s_fast = head;
    
    ListNode* pivot;
    
    if(head != nullptr && head->next != nullptr)
    {
        s_fast = head->next;
        pivot = s_fast;
    }
    else
    {
        return head;
    }
    
    while(f_fast != nullptr && s_fast != nullptr &&
        f_fast->next != nullptr && s_fast->next != nullptr)
    {
        if(f_fast->next->next != nullptr)
        {
            f_fast->next = f_fast->next->next;
            f_fast = f_fast->next;
        }
        if(s_fast->next->next != nullptr)
        {
            s_fast->next = s_fast->next->next;
            s_fast = s_fast->next;
        }
    }
    
    f_fast->next = pivot;
    
    return head;
}

ListNode* adjustSlow(ListNode* iter)
{
    return iter->next;
}

ListNode* adjustFast(ListNode* iter)
{
    return iter->next->next;
}

bool findEntry(ListNode*& fast, ListNode*& slow) {                
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = adjustSlow(slow);
        fast = adjustFast(fast);
        
        if(fast == slow)
        {
            return true;
        }
    }
    
    return false;
}

ListNode *detectCycle(ListNode *head) {
    if(head == nullptr)
        return head;
    
      ListNode* fast = head;
      ListNode* slow = head;
    
    if(findEntry(fast, slow))
    {
        ListNode* detector = head;
        
        while(detector != slow)
        {
            detector = adjustSlow(detector);
            slow = adjustSlow(slow);
        }
        
        return detector;
    }
    else
    {
        return nullptr;
    }
}

ListNode* middleNode(ListNode* head)
{
    ListNode* fast = head;
    ListNode* slow = head;
    
    while(fast != nullptr && fast->next != nullptr)
    {
    slow = slow->next;
    fast = fast->next->next;
    }
    
    return slow;
}

ListNode* reverseList(ListNode* head)
{
    if(head->next == nullptr)
    return head;
    
    ListNode* temp = head->next;
    ListNode* new_head = reverseList(temp);
    temp->next = head;
    head->next = nullptr;
    return new_head;
}

bool compare(ListNode* head, ListNode* rev_head)
{
    while(head != nullptr && rev_head != nullptr)
    {        
    if(head->val != rev_head->val)
        return false;
    
    head = head->next;
    rev_head = rev_head->next;
    }
    
    return true;
}

bool isPalindrome(ListNode* head) {
    ListNode* mid = middleNode(head);
    ListNode* rev_mid = reverseList(mid);
    
    return compare(head, rev_mid);
}

ListNode* lastElements(ListNode* head, int n)
{
    ListNode* iter = head;
    int counter = 0;

    while(iter && counter != n)
    {
        iter = iter->next;
        counter++;
    }

    if(!iter)
        return head;
    
    while(iter)
    {
        iter = iter->next;
        head = head->next;
    }

    return head;
}


int main()
{
  ListNode* head = new ListNode();
  head->val = 1;
  ListNode* second = new ListNode();
  second->val = 2;
  ListNode* third  = new ListNode();
  third->val = 2;
  ListNode* fourth = new ListNode();
  fourth->val = 1;

  head->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = nullptr;

  isPalindrome(head);
  lastElements(head, 0);

//   detectCycle(head);
}