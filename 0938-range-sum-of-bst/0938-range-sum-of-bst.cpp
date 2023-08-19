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
    int m_sum = 0;

    void rangeSumBSTHelper(const TreeNode* const node, const int low, const int high)
    {

        if (node == nullptr) {
            return;
        }

        rangeSumBSTHelper(node->left, low, high);

        if (low <= node->val && node->val <= high) {
            m_sum += node->val;
        }

        rangeSumBSTHelper(node->right, low, high);
    }

  public:
    int rangeSumBST(TreeNode* root, int low, int high)
    {
        rangeSumBSTHelper(root, low, high);

        return m_sum;
    }
};