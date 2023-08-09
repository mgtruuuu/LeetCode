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
    int sum = 0;

    bool isLeaf(const TreeNode* const node)
    {
        return (node->left == nullptr && node->right == nullptr);
    }

    void sumOfLeftLeavesHelper(const TreeNode* const node)
    {

        if (node->left != nullptr) {
            sumOfLeftLeavesHelper(node->left);

            if (isLeaf(node->left) == true) {
                sum += node->left->val;
            }
        }

        if (node->right != nullptr) {
            sumOfLeftLeavesHelper(node->right);
        }
    }

  public:
    int sumOfLeftLeaves(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }

        sumOfLeftLeavesHelper(root);

        return sum;
    }
};


/*
class Solution {
  private:
    bool isLeaf(const TreeNode* const node) {
        return (node->left == nullptr && node->right == nullptr);
    }

  public:
    int sumOfLeftLeaves(TreeNode* root) {

        if (root == nullptr) {
            return 0;
        }
        
        auto sum = 0;
        std::stack<TreeNode*> s;
        s.push(root);
        
        while (s.empty() == false) {
            
            root = s.top();
            s.pop();
            
            if (root->right != nullptr) {
                s.push(root->right);
            }
            
            if (root->left != nullptr) {
                s.push(root->left);
                
                if (isLeaf(root->left) == true) {
                    sum += root->left->val;
                }
            }
        }
        
        return sum;
    }
};
*/