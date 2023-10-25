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
        std::vector<int> res;

        std::stack<TreeNode*> s;

        while (true) {

            while (root != nullptr) {

                s.push(root);

                root = root->left;
            }

            if (s.empty() == true) {
                break;
            }
            root = s.top();
            s.pop();
            
            res.push_back(root->val);
            
            root = root->right;
        }

        return res;
    }
};
//*/


/*
// Approach 3: Morris Traversal
class Solution {
  private:
    TreeNode* predecessor(TreeNode* node)
    {
        node = node->left;

        while (node->right != nullptr) {
            node = node->right;
        }

        return node;
    }

  public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        std::vector<int> res;

        TreeNode* node = root;
        while (node != nullptr) {

            if (node->left == nullptr) {
                res.push_back(node->val);
                node = node->right;

                continue;
            }

            predecessor(node)->right = node;

            TreeNode* temp = node;
            node = node->left;

            temp->left = nullptr;
        }

        return res;
    }
};
*/