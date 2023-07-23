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
    std::stack<TreeNode*> s;
    
    void invertTreeHelper(TreeNode* root) {
        
        if (root == nullptr) {
            return;
        }
        
        if (root->left == nullptr && root->right == nullptr) {
            return;
        }
        
        auto* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        invertTreeHelper(root->left);
        invertTreeHelper(root->right);
    }
    
  public:
    TreeNode* invertTree(TreeNode* root) {
        
        invertTreeHelper(root);
        
        return root;
    }
};