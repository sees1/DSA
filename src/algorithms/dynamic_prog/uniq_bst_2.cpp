#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <gtest/gtest.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<TreeNode*> generateHelper(int start, int end, std::unordered_map<std::string, std::vector<TreeNode*>>& dp)
{
  std::string key = std::to_string(start) + "-" + std::to_string(end);

  if (dp.count(key) != 0)
    return dp[key];

  std::vector<TreeNode*> res;
  if (start > end)
  {
    res.push_back(nullptr);
    return res;
  }

  for(int root = start; root <= end; ++root)
  {
    std::vector<TreeNode*> left_trees = generateHelper(start, root - 1, dp);
    std::vector<TreeNode*> right_trees = generateHelper(root + 1, end, dp);

    for (auto& l_tree : left_trees)
    {
      for (auto& r_tree : right_trees)
      {
        TreeNode* root_node = new TreeNode(root);
        root_node->left = l_tree;
        root_node->right = r_tree;
        res.push_back(root_node);
      }
    }
  }

  return dp[key] = res;
}

std::vector<TreeNode*> generateTrees(int n)
{
  if (n == 0)
    return std::vector<TreeNode*>();

  std::unordered_map<std::string, std::vector<TreeNode*>> dp;
  return generateHelper(1, n, dp);
}

// bfs
bool isSame(std::vector<TreeNode*>&& gen_trees, std::set<std::vector<int>>& flat_trees)
{
  std::set<std::vector<int>> flatenized_gen_trees;
  for(auto& tree : gen_trees)
  {
    std::deque<TreeNode*> queue;

    queue.push_back(tree);

    std::vector<int> flat_tree;

    while(!queue.empty())
    {
      size_t l_size = queue.size();

      for(int i = 0; i < l_size; ++i)
      {
        TreeNode* next = queue.front();
        queue.pop_front();

        if (next == nullptr)
          flat_tree.push_back(-1);
        else
        {
          queue.push_back(next->left);
          queue.push_back(next->right);
          flat_tree.push_back(next->val);
        }
      }
    }

    flatenized_gen_trees.insert(flat_tree);
  }

  return flatenized_gen_trees == flat_trees;
}

TEST(DynamicTest, Test1)
{
  int n = 3;
  std::vector<int> root1 = {1, -1,  2, -1,  3, -1, -1};
  std::vector<int> root2 = {1, -1,  3,  2, -1, -1, -1};
  std::vector<int> root3 = {2,  1,  3, -1, -1, -1, -1};
  std::vector<int> root4 = {3,  1, -1, -1,  2, -1, -1};
  std::vector<int> root5 = {3,  2, -1,  1, -1, -1, -1};

  std::set<std::vector<int>> expect = {root1, root2, root3, root4, root5};
  EXPECT_EQ(isSame(generateTrees(n), expect), true);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}