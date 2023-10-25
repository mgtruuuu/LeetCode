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


/*
// Approach 2-1: Iteration
class Solution {
  public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        std::vector<int> res;
        std::stack<TreeNode*> s;

        s.push(root);
        while (s.empty() == false) {
            
            root = s.top();
            s.pop();

            if (root == nullptr) {
                continue;
            }
            
            res.push_back(root->val);    
            
            s.push(root->right);
            s.push(root->left);
        }

        return res;
    }
};
*/


// Approach 2-2: Iteration
/*
class Solution {
  public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        std::vector<int> res;
        std::stack<TreeNode*> s;

        if (root != nullptr) {
            s.push(root);
        }

        while (s.empty() == false) {
            
            root = s.top();
            s.pop();

            res.push_back(root->val);

            if (root->right != nullptr) {
                s.push(root->right);
            }

            if (root->left != nullptr) {
                s.push(root->left);
            }            
        }

        return res;
    }
};
*/


/*
// Approach 2-3: Iteration
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


///*
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
    vector<int> preorderTraversal(TreeNode* root)
    {
        std::vector<int> res;

        TreeNode* node = root;
        while (node != nullptr) {

            res.push_back(node->val);

            if (node->left == nullptr) {
                // res.push_back(node->val);
                node = node->right;

                continue;
            }
            else if (node->right == nullptr) {
                node = node->left;

                continue;
            }

            predecessor(node)->right = node->right;

            TreeNode* temp = node;
            node = node->left;

            temp->left = nullptr;
            temp->right = nullptr;
        }

        return res;
    }
};
//*/