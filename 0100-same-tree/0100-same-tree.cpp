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


///*
// Approach 1: Recursion
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

        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
//*/



/*
// Approach 2: Iteration
class Solution {
  public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        std::stack<TreeNode*> s1, s2;

        s1.push(p);
        s2.push(q);
        while (s1.empty() == false && s2.empty() == false) {

            auto* node1 = s1.top();
            s1.pop();
            auto* node2 = s2.top();
            s2.pop();

            if (node1 == nullptr || node2 == nullptr) {

                if (node1 == nullptr && node2 == nullptr) {
                    continue;
                }

                return false;
            }

            if (node1->val != node2->val) {
                return false;
            }

            s1.push(node1->right);
            s1.push(node1->left);
            s2.push(node2->right);
            s2.push(node2->left);
        }

        return s1.empty() && s2.empty() ? true : false;
    }
};
*/