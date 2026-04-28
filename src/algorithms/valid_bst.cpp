#include <limits>


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    
  bool isPossible(TreeNode* root, int& min, int& max)
  {
    if (root == nullptr)
      return true;

    if (root->val > min && root->val < max)
    {
      bool l = isPossible(root->left, min, root->val);
      bool r = isPossible(root->right, root->val, max);

      return l && r;
    }
    
    return false;
  }
  
  bool isValidBST(TreeNode* root) {
    int left_piv = std::numeric_limits<int>::min();
    int right_piv = std::numeric_limits<int>::max();
    return isPossible(root, left_piv, right_piv);
  }
};

int main() {
  TreeNode* root = new TreeNode(2);
  root->left = new TreeNode(1);
  root->right = new TreeNode(3);

  Solution s;
  s.isValidBST(root);
}