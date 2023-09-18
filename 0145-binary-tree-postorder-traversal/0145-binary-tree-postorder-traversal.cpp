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



// Approach 3: Iterative Postorder Traversal
class Solution {
  public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        std::vector<int> res;
        std::stack<TreeNode*> s;

        TreeNode* curr = root;
        TreeNode* last;

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
            }
            else {
                
                s.pop();
                
                res.push_back(curr->val);
                
                last = curr;
                curr = nullptr;                
            }
        }

        return res;
    }
};



/*
// Approach 2: Iterative Preorder Traversal: Tweak the Order of the Output
class Solution {
  public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        std::vector<int> output;

        if (root == nullptr) {
            return output;
        }

        stack<TreeNode*> s;
        s.push(root);

        TreeNode* node;
        while (s.empty() == false) {

            node = s.top();
            s.pop();

            output.push_back(node->val);

            if (node->left != nullptr) {
                s.push(node->left);
            }
            if (node->right != nullptr) {
                s.push(node->right);
            }
        }

        std::reverse(output.begin(), output.end());
        return output;
    }
};
*/



/*
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
*/

