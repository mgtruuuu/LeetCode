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
    int recFcn(TreeNode* node, const int depth) {

        if (node == nullptr) {
            return depth;
        }
            
        return std::max(recFcn(node->left, depth + 1), recFcn(node->right, depth + 1));
    }
    
    int maxDepth(TreeNode* root) {
        
        return recFcn(root, 0);
    }
};