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
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        std::vector<std::vector<int>> res;

        std::queue<TreeNode*> q;
        q.push(root);

        while (true) {

            std::vector<int> vals_same_level;

            auto len_q = q.size();

            while (len_q-- != 0) {

                const auto* const node = q.front();
                q.pop();

                if (node != nullptr) {

                    vals_same_level.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }

            if (q.empty() == true) {
                break;
            }
            else {
                res.push_back(vals_same_level);
            }
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
};