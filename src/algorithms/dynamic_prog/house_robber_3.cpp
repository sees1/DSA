#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <sstream>
#include <numeric>
#include <limits>
#include <gtest/gtest.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int helper(TreeNode* root, bool rob, std::unordered_map<std::string, int>& dp)
{
  if (root == nullptr)
    return 0;

  std::stringstream ss;
  ss << root;
  std::string key = ss.str() + "-" + std::to_string(static_cast<int>(rob));

  if(dp.count(key) != 0)
    return dp[key];

  int ans = 0;

  if (rob)
  {
    int rob = root->val + helper(root->left, false, dp) + helper(root->right, false, dp);
    int dont_rob = helper(root->left, true, dp) + helper(root->right, true, dp);

    ans = std::max(rob, dont_rob);
  }
  else
  {
    int dont_rob = helper(root->left, true, dp) + helper(root->right, true, dp);
    
    ans = dont_rob;
  }

  return dp[key] = ans;
}

int rob(TreeNode* root) {
  std::unordered_map<std::string, int> dp;
  return helper(root, true, dp);
}

TEST(DynamicTest, Test1)
{
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(4);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right->right = new TreeNode(1);
  EXPECT_EQ(rob(root), 9);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}