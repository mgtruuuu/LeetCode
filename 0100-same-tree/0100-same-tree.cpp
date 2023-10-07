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
class Solution {
  public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (p == nullptr) {
            return (q == nullptr ? true : false);
        }
        else if (q == nullptr) {
            return false;
        }
        // if (p == nullptr && q == nullptr) {
        //     return true;
        // }
        // if (p == nullptr || q == nullptr) {
        //     return false;
        // }

        if (p->val != q->val) {
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
*/

class Solution {
  public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (p == nullptr) {
            return (q == nullptr ? true : false);
        }
        else if (q == nullptr) {
            return false;
        }

        std::stack<TreeNode*> s_p, s_q;

        const auto lambda = [&](TreeNode* p, TreeNode* q) -> bool {
            if (p == nullptr) {
                if (q == nullptr) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else if (q == nullptr) {
                return false;
            }
            else {
                s_p.push(p);
                s_q.push(q);
                return true;
            }
        };

        s_p.push(p);
        s_q.push(q);
        while (s_p.empty() == false && s_q.empty() == false) {

            const auto* node_p = s_p.top();
            s_p.pop();
            const auto* node_q = s_q.top();
            s_q.pop();

            if (node_p->val != node_q->val) {
                return false;
            }

            if (lambda(node_p->left, node_q->left) == false || lambda(node_p->right, node_q->right) == false) {
                return false;
            }
        }

        return s_p.empty() && s_p.empty() ? true : false;
    }
};