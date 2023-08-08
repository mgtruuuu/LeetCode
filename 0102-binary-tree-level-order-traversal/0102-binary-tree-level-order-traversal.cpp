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


// Approach 2-1: Iteration
class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        std::vector<std::vector<int>> res;

        std::queue<TreeNode*> q;
        q.push(root);

        while (q.empty() == false) {

            std::vector<int> vals;

            const auto len_q = q.size();
            for (auto idx = std::size_t(0); idx != len_q; ++idx) {

                const auto* const curr = q.front();
                q.pop();

                if (curr != nullptr) {
                    vals.push_back(curr->val);
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }

            res.push_back(vals);
        }

        res.erase(res.end() - 1);
        return res;
    }
};


/*
// Approach 2-2: Iteration
class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        std::vector<std::vector<int>> res;

        std::queue<TreeNode*> queue_prev;
        queue_prev.push(root);

        while (true) {

            std::queue<TreeNode*> queue_curr;
            std::vector<int> vals;

            while (queue_prev.empty() == false) {
                const auto* const curr = queue_prev.front();
                queue_prev.pop();

                if (curr != nullptr) {
                    vals.push_back(curr->val);
                    queue_curr.push(curr->left);
                    queue_curr.push(curr->right);                    
                }
            }

            if (queue_curr.empty() == true) {
                break;
            }

            res.push_back(vals);
            queue_prev = queue_curr;
        }

        return res;
    }
};
*/


/*
// Approach 1: Recursion
class Solution {
  private:
    std::vector<std::vector<int>> levels;
    void levelOrderHelper(const TreeNode* const node, const std::size_t level)
    {
        if (node == nullptr) {
            return;
        }

        if (levels.size() <= level) {
            levels.resize(level + 1);
        }

        levels[level].push_back(node->val);
        levelOrderHelper(node->left, level + 1);
        levelOrderHelper(node->right, level + 1);
    }

  public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        levelOrderHelper(root, 0);

        return levels;
    }
};
*/