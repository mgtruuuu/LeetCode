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

/*
// Approach 1 - 1 : Recursion
class Solution {
  private:
    bool pathSum(TreeNode* node, int targetSum)
    {
        if (node->left == nullptr && node->right == nullptr) {
            return node->val == targetSum ? true : false;
        }

        targetSum -= node->val;

        if (node->left != nullptr && pathSum(node->left, targetSum) == true) {
            return true;
        }

        if (node->right != nullptr && pathSum(node->right, targetSum) == true) {
            return true;
        }

        return false;
    }

  public:
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        return root == nullptr ? false : pathSum(root, targetSum);
    }
};
*/


class Solution {
  public:
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if (root == nullptr) {
            return false;
        }

        targetSum -= root->val;

        return (root->left == nullptr && root->right == nullptr)
                   ? (targetSum == 0)
                   : (hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum));
    }
};