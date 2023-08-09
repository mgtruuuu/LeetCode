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
// Approach 1: Linear Time
class Solution {
  public:
    int countNodes(TreeNode* root)
    {
        return (root != nullptr) ? 1 + countNodes(root->left) + countNodes(root->right) : 0;
        
        // // if (root == nullptr) {
        // //     return 0;
        // // }

        // // return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
*/



// Approach 2: Linear Time
class Solution {
  private:
    int computeDepth(const TreeNode* node)
    {

        if (node == nullptr) {
            return -1;
        }

        auto depth = 0;

        while (node->left != nullptr) {

            node = node->left;
            ++depth;
        }

        return depth;
    }

    int twoPower(const int n)
    {
        return (1 << n);
    }

    bool exists(const int idx, const int depth, const TreeNode* node)
    {
        auto left = 0;
        auto right = twoPower(depth) - 1;
        auto pivot = 0;

        for (auto i = 0; i != depth; ++i) {

            pivot = left + (right - left) / 2;
            if (idx <= pivot) {

                node = node->left;
                right = pivot - 1;
            }
            else {

                node = node->right;
                left = pivot + 1;
            }
        }

        return (node != nullptr);
    }

  public:
    int countNodes(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }

        const auto depth = computeDepth(root);

        if (depth == 0) {
            return 1;
        }

        auto left = 0;
        auto right = twoPower(depth) - 1;
        auto pivot = 0;

        while (left <= right) {

            pivot = left + (right - left) / 2;

            if (exists(pivot, depth, root) == true) {
                left = pivot + 1;
            }
            else {
                right = pivot - 1;
            }
        }

        return twoPower(depth) - 1 + left;
    }
};