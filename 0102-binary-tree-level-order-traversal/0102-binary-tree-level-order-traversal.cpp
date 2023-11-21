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
// Approach 2-1: Iteration
class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode* root)
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
                return res;
            }
            else {
                res.push_back(vals_same_level);
            }
        }

        return res; // cannot be run
    }
};
*/



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


///*
// Approach 1: Recursion
class Solution {
  private:
    std::vector<std::vector<int>> levels;

    void levelOrderHelper(const TreeNode* const node, const std::size_t level)
    {
        if (node == nullptr) {
            return;
        }

        if (levels.size() < level + 1) {
            
            if (levels.capacity() < level + 1) {
                levels.reserve(2 * level);
            }
            
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
//*/