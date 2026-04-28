#include <vector>

struct TreeNode { 
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) { }
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) { }
};

void helper(TreeNode* root, std::vector<int>& res, int level)
{
  if (root == nullptr)
    return;

  if (static_cast<int>(res.size() - 1) < level)
  {
    res.push_back(root->val);
  }

  helper(root->right, res, level + 1);
  helper(root->left, res, level + 1);
}

std::vector<int> rightSideView(TreeNode* root)
{
  std::vector<int> res;
  helper(root, res, 0);

  return res;
}

int main() { 
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(4);

  auto res = rightSideView(root);
}