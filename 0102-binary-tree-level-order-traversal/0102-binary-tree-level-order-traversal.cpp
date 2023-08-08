/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


// Approach 1: Recursion
class Solution {
  private:
    std::vector<std::vector<int>> levels;
    void levelOrderHelper(const TreeNode* const node, const std::size_t level)
    {

        if (node == nullptr) {
            return;
        }

        if (levels.size() <= level) {
            levels.resize(level + 1);
        }

        levels[level].push_back(node->val);
        levelOrderHelper(node->left, level + 1);
        levelOrderHelper(node->right, level + 1);
    }

  public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        levelOrderHelper(root, 0);

        return levels;
    }
};