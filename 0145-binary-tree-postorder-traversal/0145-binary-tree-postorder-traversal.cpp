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


// Approach 1: Recursive Postorder Traversal
class Solution {

  private:
    std::vector<int> postorder;
    void postorderTraversalHelper(const TreeNode* const node)
    {
        if (node == nullptr) {
            return;
        }

        postorderTraversalHelper(node->left);
        postorderTraversalHelper(node->right);
        postorder.push_back(node->val);
    }

  public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        postorderTraversalHelper(root);

        return postorder;
    }
};



// Approach 2: Iteration
/*
class Solution {
  public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        std::vector<int> res;
        std::stack<TreeNode*> s;

        TreeNode* curr = root;
        TreeNode* last = nullptr;

        while (true) {

            while (curr != nullptr) {

                s.push(curr);

                curr = curr->left;
            }

            if (s.empty() == true) {
                break;
            }
            curr = s.top();

            if (curr->right != nullptr && curr->right != last) {

                curr = curr->right;

                continue;
            }

            last = curr;
            s.pop();
            res.push_back(last->val);

            curr = nullptr;
        }

        return res;
    }
};
*/
