#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <string>

struct TreeNode
{
  TreeNode() : left(nullptr), right(nullptr) {};
  TreeNode(int temp) : val(temp) {};
  int val;
  TreeNode* left;
  TreeNode* right;
};

struct Node
{
  int val;
  Node* left = nullptr;
  Node* right = nullptr;
  Node* next = nullptr;
};

void tree(TreeNode* root, std::vector<int>& v)
{
  v.push_back(root->val);

  if(root->left != nullptr)
    tree(root->left, v);
  if(root->right != nullptr)
    tree(root->right, v);
}

std::vector<int> preorderTraversal(TreeNode* root) {
  std::vector<int> vec;
  
  if(root == nullptr)
    return vec;
  
  tree(root, vec);
  return vec;
}

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
  std::vector<std::vector<int>> ret;
  
  std::queue<TreeNode*> q;

  if(root == nullptr)
    return ret;

  q.push(root);
  
  while(!q.empty())
  {
    std::vector<int> temp;
    
    size_t size_q = q.size();
    
    for(size_t i = 0; i < size_q; ++i)
    {
      temp.push_back(q.front()->val);

      if(q.front()->left != nullptr)
        q.push(q.front()->left);
      if(q.front()->right != nullptr)
        q.push(q.front()->right);

      q.pop();
    }
    
    ret.push_back(temp);
  }
  
  return ret;
}

Node* connect(Node* root)
{
  std::queue<Node*> q;

  if(root == nullptr)
    return root;
  else
    q.push(root);


  while(!q.empty())
  {
    std::vector<Node*> next;

    size_t q_size = q.size();

    for(size_t i = 0; i < q_size; ++i)
    {
      next.push_back(q.front());

      if(q.front()->left != nullptr)
        q.push(q.front()->left);
      if(q.front()->right != nullptr)
        q.push(q.front()->right);

      q.pop();
    }

    for(size_t i = 0; i < next.size() - 1; ++i)
    {
      next[i]->next = next[i + 1];
    }

    next[next.size() - 1]->next = nullptr;
  }

  return root;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if(root == p || root == q || root == nullptr)
    return root;

  TreeNode* parent1 = lowestCommonAncestor(root->left, p, q);
  TreeNode* parent2 = lowestCommonAncestor(root->right, p, q);

  if(parent1 && parent2)
    return root;
  else
    return parent1 ? parent1 : parent2;      
}

std::pair<std::string, int> convertString(std::string& s, size_t& i)
{
  std::string temp;

  while(s[i] != ',' && i < s.size())
  {
    temp += s[i];
    ++i;
  }

  ++i;

  if(temp != "n")
    return {temp, std::stoi(temp)};
  else
    return {temp, 0};
}

// Encodes a tree to a single string.
std::string serialize(TreeNode* root) {
  std::queue<TreeNode*> q;

  std::string s;

  if(root != nullptr)
    q.push(root);
  else
    return "";

  while(!q.empty())
  {
    if(q.front() != nullptr)
      s += std::to_string(q.front()->val);
    else
      s += 'n';
    
    s += ',';

    if(q.front() != nullptr)
    {
      q.push(q.front()->left);
      q.push(q.front()->right);
    }

    q.pop();
  }

  s.resize(s.size() - 1);

  return s;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(std::string data) {
  size_t i = 0;

  std::string temp;
  int value;
  
  std::tie(temp, value) = convertString(data, i);

  TreeNode* root;

  if(temp != "n")
    root = new TreeNode(value);
  else
    return nullptr;

  std::queue<TreeNode*> q;
  q.push(root);

  while(!q.empty())
  {
    std::tie(temp, value) = convertString(data, i);

    if(temp != "n")
    {
      q.front()->left = new TreeNode(value);
      q.push(q.front()->left);
    }

    std::tie(temp, value) = convertString(data, i);

    if(temp != "n")
    {
      q.front()->right = new TreeNode(value);
      q.push(q.front()->right);
    }

    q.pop();
  }

  return root;
}

bool isSymmetric(TreeNode* root) {
  std::queue<TreeNode*> q;

  q.push(root);

  while(!q.empty())
  {
    std::vector<std::pair<int, bool>> ex;

    size_t q_size = q.size();
    
    for(size_t i = 0; i < q_size; ++i)
    {
      if(q.front() == nullptr)
        ex.push_back({-1, 0});
      else
        ex.push_back({q.front()->val, 1});
      
      if(q.front() != nullptr)
        q.push(q.front()->left);
      if(q.front() != nullptr)
        q.push(q.front()->right);
      
      q.pop();
    }
    
    size_t act_size = ex.size();
    size_t prog_size = act_size - 1;
    for(size_t i = 0; i < act_size / 2; ++i)
    {
      if(ex[i].second != ex[prog_size - i].second ||
         ex[i].first  != ex[prog_size - i].first)
        return false;
    }
  }
  
  return true;
}



bool hasPathSum(TreeNode* root, int targetSum) {
  if(root == nullptr)
    return false;
  
  targetSum = targetSum - root->val;
  
  bool answer = false;
  bool isLeaf = false;

  if(root->left != nullptr)
    answer = answer | hasPathSum(root->left, targetSum);
  else
    isLeaf = true;
  if(root->right != nullptr)
  {
    answer = answer | hasPathSum(root->right, targetSum);
    isLeaf = false;
  }
  if(isLeaf && targetSum == 0)
    answer = answer | true;
  
  return answer;
}

void operator<<(std::ostream& os, std::vector<int> v)
{
  std::for_each(v.begin(), v.end(), [&os](auto&& item) {os << item;});
}

void operator<<(std::ostream& os, std::vector<std::vector<int>> v)
{
  std::for_each(v.begin(), v.end(), [&os](auto&& item) {os << item;});
}

int main()
{
  TreeNode* root = new TreeNode{};
  TreeNode* l1_left = new TreeNode{};
  TreeNode* l1_right = new TreeNode{};
  TreeNode* l2_left_left = new TreeNode{};
  TreeNode* l2_right_left = new TreeNode{};
  TreeNode* l2_right_right = new TreeNode{};
  TreeNode* l3_left_left_left = new TreeNode{};
  TreeNode* l3_left_left_right = new TreeNode{};
  TreeNode* l3_right_right_right = new TreeNode{};

  root->val = 5;
  root->left = l1_left;
  root->right = l1_right;
  
  l1_left->val = 4;
  l1_left->left = l2_left_left;
  l1_left->right = nullptr;

  l1_right->val = 8;
  l1_right->left = l2_right_left;
  l1_right->right = l2_right_right;

  l2_left_left->val = 11;
  l2_left_left->left = l3_left_left_left;
  l2_left_left->right = l3_left_left_right;

  l3_left_left_left->val = 7;
  l3_left_left_left->left = nullptr;
  l3_left_left_left->right = nullptr;

  l3_left_left_right->val = 2;
  l3_left_left_right->left = nullptr;
  l3_left_left_right->right = nullptr;

  l2_right_left->val = 13;
  l2_right_left->left = nullptr;
  l2_right_left->right = nullptr;

  l2_right_right->val = 4;
  l2_right_right->left = nullptr;
  l2_right_right->right = l3_right_right_right;

  l3_right_right_right->val = 1;
  l3_right_right_right->left = nullptr;
  l3_right_right_right->right = nullptr;


  // std::cout << preorderTraversal(root);
  // std::cout << levelOrder(root);
  // std::cout << hasPathSum(root, 22);
  deserialize(serialize(root));

  return 0;
}