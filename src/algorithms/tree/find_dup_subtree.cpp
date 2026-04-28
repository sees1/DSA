#include <vector>
#include <string>
#include <map>
#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left = nullptr;
  TreeNode *right = nullptr;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::string findSimSubTreeHelper(TreeNode* root, std::map<std::string, std::vector<TreeNode*>>& subtree)
{
  if (root == nullptr)
    return "*";

  std::string left = findSimSubTreeHelper(root->left, subtree);
  if (left == "*")
    left = "#";
  std::string cur = std::to_string(root->val);
  std::string right = findSimSubTreeHelper(root->right, subtree);

  std::string res = left + cur + right;
  subtree[res].push_back(root);

  return res;
}

std::vector<TreeNode*> findSimSubTree(TreeNode* root)
{
  std::map<std::string, std::vector<TreeNode*>> subtrees;

  findSimSubTreeHelper(root, subtrees);

  std::vector<TreeNode*> res;

  std::for_each(subtrees.begin(), subtrees.end(),
    [&res](auto& elem)
    {
      if (elem.second.size() > 1)
        res.push_back(elem.second[0]);
    }
  );

  return res;
}

int main()
{
  TreeNode* root = new TreeNode(0);
  root->left = new TreeNode(0);
  root->left->left = new TreeNode(0);
  root->right = new TreeNode(0);
  root->right->right = new TreeNode(0);
  root->right->right->right = new TreeNode(0);

  auto res = findSimSubTree(root);
}