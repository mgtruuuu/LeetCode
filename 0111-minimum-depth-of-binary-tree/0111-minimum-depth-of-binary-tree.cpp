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

class Solution {
  public:
    int minDepth(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }

        if (root->left == nullptr) {
            return minDepth(root->right) + 1;
        }
        
        if (root->right == nullptr) {
            return minDepth(root->left) + 1;
        }
        
        return std::min(minDepth(root->right), minDepth(root->left)) + 1;
        
        
        const auto left_min_depth = minDepth(root->left);

        const auto right_min_depth = minDepth(root->right);

        if (left_min_depth == 0) {
            return right_min_depth + 1;
        }

        if (right_min_depth == 0) {
            return left_min_depth + 1;
        }

        return std::min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};