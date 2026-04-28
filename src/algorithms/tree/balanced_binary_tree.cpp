#include <vector>
#include <numeric>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int helper(TreeNode* root, int level, bool& is_balanced)
{
  if (root == nullptr)
      return -1;

  int left = helper(root->left, level + 1, is_balanced);
  int right = helper(root->right, level + 1, is_balanced);

  if (left != -1 && right != -1)
  {
      if (left - right > 1 || right - left > 1)
          is_balanced = false;
      return std::max(left, right);
  }
  else if (left == -1 && right == -1)
      return level;
  else if (left != -1)
  {
      if (left - level > 1)
          is_balanced = false;
      return left;
  }
  else if (right != -1)
  {
      if (right - level > 1)
          is_balanced = false;
      return right;
  }

  return level;
}

bool isBalanced(TreeNode* root) {
  bool fl = true;
  auto res = helper(root, 1, fl);

  return fl;
}

int main() { 
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(3);
  root->left->left->left = new TreeNode(4);
  root->left->left->right = new TreeNode(4);

  TreeNode* root2 = new TreeNode(1);
  root2->right = new TreeNode(2);
  root2->right->right = new TreeNode(3);

  auto res = isBalanced(root2);
}