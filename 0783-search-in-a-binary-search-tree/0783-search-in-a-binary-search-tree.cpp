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
class Solution {
  public:
    TreeNode* searchBST(TreeNode* root, int val)
    {
        while (root != nullptr) {
            if (root->val < val) {
                root = root->right;
            }
            else if (root->val > val) {
                root = root->left;
            }
            else {
                return root;
            }
        }

        return nullptr;
    }
};
*/


class Solution {
  public:
    TreeNode* searchBST(TreeNode* root, int val)
    {
        if (root == nullptr) {
            return root;
        }

        if (root->val < val) {
            return searchBST(root->right, val);
        }
        else if (root->val > val) {
            return searchBST(root->left, val);
        }
        else {
            return root;
        }
    }
};