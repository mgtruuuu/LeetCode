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
// Approach 1: Recursive Approach
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
*/


///*
// Approach 2: Iterating method using Stack
class Solution {
  public:
    vector<int> inorderTraversal(TreeNode* root)
    {

        if (root == nullptr) {
            return {};
        }

        std::vector<int> res;

        std::stack<TreeNode*> s;
        // s.push(root);

        while (true) {

            while (root != nullptr) {

                s.push(root);

                root = root->left;
            }

            if (s.empty() == true) {
                break;
            }

//             auto* node = s.top();
//             s.pop();

//             res.push_back(node->val);

//             root = node->right;
            
            root = s.top();
            s.pop();
            
            res.push_back(root->val);
            
            root = root->right;
        }

        return res;
    }
};
//*/