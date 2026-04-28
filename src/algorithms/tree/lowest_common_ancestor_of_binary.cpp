#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (root == nullptr)
    return nullptr;
  else if (root == p || root == q)
  {
    return root;
  }
  else
  {
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left == nullptr && right != nullptr)
        return right;
    else if (left != nullptr && right == nullptr)
        return left;
    else if (left != nullptr && right != nullptr)
        return root;

    return nullptr;
  }
}

int main() {
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);

  TreeNode* p = root->left;
  TreeNode* q = root->right;

  TreeNode* res = lowestCommonAncestor(root, p, q);
}