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
    int rangeSumBST(TreeNode* root, int low, int high)
    {
        auto sum = 0;
        bool end = false;
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

            if (low <= root->val && root->val <= high) {
                sum += root->val;
            }
            else if (high < root->val) {
                break;
            }

            root = root->right;
        }

        return sum;
    }
};


/*
// Approach 1: Depth First Search - Recursive
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
*/