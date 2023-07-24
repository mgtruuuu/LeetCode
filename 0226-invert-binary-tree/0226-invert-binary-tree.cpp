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
// Approach 1: Recursive
class Solution {
  public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (root == nullptr) {
            return root;
        }

        auto* temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
*/


// Approach 2: Iterative
class Solution {
  public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (root == nullptr) {
            return root;
        }

        std::queue<TreeNode*> q;
        q.push(root);

        while (q.empty() == false) {
            auto* curr = q.front();
            q.pop();

            auto* temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;

            if (curr->left != nullptr) {
                q.push(curr->left);
            }

            if (curr->right != nullptr) {
                q.push(curr->right);
            }
        }

        return root;
    }
};