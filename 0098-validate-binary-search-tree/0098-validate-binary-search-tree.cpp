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

///*
// Approach 1: Recursive Traversal with Valid Range
class Solution {
  private:
    bool isValidBSTHelper(TreeNode* node, TreeNode* lower_limit = nullptr, TreeNode* upper_limit = nullptr)
    {
        if (node == nullptr) {
            return true;
        }

        // if (node->left != nullptr && node->left->val >= node->val) {
        //     return false;
        // }
        // if (node->right != nullptr && node->right->val <= node->val) {
        //     return false;
        // }

        if (lower_limit != nullptr && lower_limit->val >= node->val) {
            return false;
        }

        if (upper_limit != nullptr && upper_limit->val <= node->val) {
            return false;
        }

        return isValidBSTHelper(node->left, lower_limit, node) && isValidBSTHelper(node->right, node, upper_limit);
    }

  public:
    bool isValidBST(TreeNode* root)
    {
        return isValidBSTHelper(root);
    }
};
//*/


// Approach 2: Iterative Traversal with Valid Range


// Approach 3: Recursive Inorder Traversal


// Approach 4: Iterative Inorder Traversal