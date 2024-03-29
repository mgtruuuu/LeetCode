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



// Approach 2 - 2: Recursive Tree Traversal (Pre-order)
class Solution {
  private:
    int sumOfLeftLeavesHelper(const TreeNode* const node, const bool is_left)
    {
        if (node->left == nullptr && node->right == nullptr) {
            return is_left == true ? node->val : 0;
        }

        auto total = 0;

        if (node->left != nullptr) {
            total += sumOfLeftLeavesHelper(node->left, true);
        }

        if (node->right != nullptr) {
            total += sumOfLeftLeavesHelper(node->right, false);
        }

        return total;
    }

  public:
    int sumOfLeftLeaves(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }

        return sumOfLeftLeavesHelper(root, false);
    }
};



/*
// Approach 2 - 1: Recursive Tree Traversal (Pre-order)
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
*/



/*
// Approach 1: Iterative Tree Traversal (Pre-order)
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