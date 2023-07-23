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
// Approach 1: BFS
class Solution {
  public:
    int minDepth(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }

        std::queue<TreeNode*> q;
        q.push(root);
        auto depth = 1;

        while (q.empty() == false) {
            auto len_q = q.size();

            while (len_q-- != 0) {
                const auto* node = q.front();

                // The first leaf would be at minimum depth, hence return it.
                if (node->left == nullptr && node->right == nullptr) {
                    return depth;
                }
                
                q.pop();

                if (node->left != nullptr) {
                    q.push(node->left);    
                }
                
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            ++depth;
        }

        return -1;
    }
};
*/



// Approach 2: DFS
class Solution {
  public:
    int minDepth(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }

        if (root->left == nullptr) {
            return minDepth(root->right) + 1;
        }

        if (root->right == nullptr) {
            return minDepth(root->left) + 1;
        }

        return std::min(minDepth(root->right), minDepth(root->left)) + 1;
    }
};
