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


// Approach 1: Recursion
/*
class Solution {
  private:
    std::vector<int> answer;
    
    void dfs(const TreeNode* const node) {
        
        if (node == nullptr) {
            return;
        }
        
        // Visit the root first, then the left subtree, then the right subtree.
        answer.push_back(node->val);
        dfs(node->left);
        dfs(node->right);
    }
    
  public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        dfs(root);

        return answer;
    }
};
*/



// Approach 2-1: Iteration
class Solution {
  public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        std::vector<int> res;
        std::stack<TreeNode*> s;

        if (root == nullptr) {
            return res;
        }
        
        s.push(root);

        do {

            root = s.top();
            s.pop();

            res.push_back(root->val);

            if (root->right != nullptr) {
                s.push(root->right);
            }

            if (root->left != nullptr) {
                s.push(root->left);
            }

        } while (s.empty() == false);

        return res;
    }
};



// Approach 2-2: Iteration
/*
class Solution {
  public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        std::vector<int> res;
        std::stack<TreeNode*> s;

        while (true) {

            while (root != nullptr) {

                res.push_back(root->val);
                s.push(root);
                root = root->left;
            }

            if (s.empty() == true) {
                break;
            }

            root = s.top()->right;
            s.pop();
        }

        return res;
    }
};
*/