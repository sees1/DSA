#include <iostream>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool helper(TreeNode* left_tree_root, TreeNode* right_tree_root)
{
  if (left_tree_root == nullptr && right_tree_root == nullptr)
    return true;
  else if (left_tree_root == nullptr || right_tree_root == nullptr)
    return false;

  return left_tree_root->val == right_tree_root->val && helper(left_tree_root->left, right_tree_root->right) && 
                                                        helper(left_tree_root->right, right_tree_root->left);
}

bool isSymmetric(TreeNode* root)
{
  return helper(root->left, root->right);
}

int main() {
  TreeNode* root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->right = new TreeNode(2);
  root1->left->left = new TreeNode(3);
  root1->left->right = new TreeNode(4);
  root1->right->left = new TreeNode(4);
  root1->right->right = new TreeNode(3);

  TreeNode* root2 = new TreeNode(1);
  root2->left = new TreeNode(2);
  root2->right = new TreeNode(2);
  root2->left->right = new TreeNode(3);
  root2->right->right = new TreeNode(3);

  auto fl1 = isSymmetric(root1);
}