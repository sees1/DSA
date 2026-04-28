struct Node{
  int val;
  Node* prev;
  Node* next;
  Node* child;
};

Node* flatten(Node* head) {
  Node* iter = head;
  Node* tmp;
  while(iter != nullptr)
  {
    if(iter->child != nullptr)
    {
      Node* child_last_node = flatten(iter->child);

      if(iter->next == nullptr)
      {
        child_last_node->next = nullptr;

        iter->next = iter->child;
        iter->child->prev = iter;
        
        iter->child = nullptr;
      }
      else
      {
        tmp = iter->next;
        
        child_last_node->next = tmp;
        tmp->prev = child_last_node;

        iter->next = iter->child;
        iter->child->prev = iter;
        
        iter->child = nullptr;
      }
    }
    
    if(iter->next == nullptr)
      return iter;
    else
      iter = iter->next;
  }

  return head;
}

int main(){
  Node* head = new Node();
  Node* l1_second = new Node();
  Node* l1_third = new Node();
  Node* l1_fourth = new Node();
  Node* l1_fifth = new Node();
  Node* l1_sixs = new Node();

  Node* l2_head = new Node();
  Node* l2_second = new Node();
  Node* l2_third = new Node();
  Node* l2_fourth = new Node();

  Node* l3_head = new Node();
  Node* l3_second = new Node();

  head->next = l1_second;
  head->prev = nullptr;
  head->child = nullptr;

  l1_second->next = l1_third;
  l1_second->prev = head;
  l1_second->child = nullptr;

  l1_third->next = l1_fourth;
  l1_third->prev = l1_second;
  l1_third->child = l2_head;

  l1_fourth->next = l1_fifth;
  l1_fourth->prev = l1_third;
  l1_fourth->child = nullptr;
  
  l1_fifth->next = l1_sixs;
  l1_fifth->prev = l1_fourth;
  l1_fifth->child = nullptr;

  l1_sixs->next = nullptr;
  l1_sixs->prev = l1_fifth;
  l1_sixs->child = nullptr;

  l2_head->prev = nullptr;
  l2_head->next = l2_second;
  l2_head->child = nullptr;

  l2_second->next = l2_third;
  l2_second->prev = l2_head;
  l2_second->child = l3_head;

  l2_third->next = l2_fourth;
  l2_third->prev = l2_second;
  l2_third->child = nullptr;

  l2_fourth->next = nullptr;
  l2_fourth->prev = l2_third;
  l2_fourth->child = nullptr;

  l3_head->next = l3_second;
  l3_head->prev = nullptr;
  l3_head->child = nullptr;

  l3_second->next = nullptr;
  l3_second->prev = l3_head;
  l3_second->child = nullptr;

  flatten(head);
}