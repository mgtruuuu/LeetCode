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
  private:
    std::vector<int> inorders;
    
    void inorderHelper(TreeNode* root) {

        if (root == nullptr) {
            return;
        }
        
        inorderHelper(root->left);    
        inorders.push_back(root->val);
        inorderHelper(root->right);
    }
    
  public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        inorderHelper(root);
        
        return inorders;
    }
};