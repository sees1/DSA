#include <iostream>
#include <string>
#include <vector>
#include <deque>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
  std::vector<std::vector<int>> res;
  if (!root) return res;
  
  std::deque<TreeNode*> que;

  que.push_back(root);
  bool reverse = false;

  while(!que.empty())
  {
    int size = que.size();
    std::vector<int> level;

    for(int i = 0; i < size; ++i)
    {
      TreeNode* node;
      if (reverse)
      {
        node = que.back();
        que.pop_back();
        if (node->right) que.push_front(node->right);
        if (node->left) que.push_front(node->left);
      }
      else
      {
        node = que.front();
        que.pop_front();
        if (node->left) que.push_back(node->left);
        if (node->right) que.push_back(node->right);
      }
      level.push_back(node->val);
    }

    res.push_back(level);
    reverse = !reverse;
  }

  return res;
}

int main() {
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  auto res = zigzagLevelOrder(root);
}