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
    void delNodesHelper(TreeNode* node, std::unordered_set<int>& to_delete, std::vector<TreeNode*>& nodes)
    {
        if (node == nullptr) {
            return;
        }

        delNodesHelper(node->left, to_delete, nodes);
        delNodesHelper(node->right, to_delete, nodes);

        if (to_delete.find(node->val) != to_delete.end()) {

            if (node->right != nullptr && to_delete.find(node->right->val) == to_delete.end()) {
                nodes.push_back(node->right);
            }

            if (node->left != nullptr && to_delete.find(node->left->val) == to_delete.end()) {
                nodes.push_back(node->left);
            }
        }

        if (node->right != nullptr && to_delete.find(node->right->val) != to_delete.end()) {
            node->right = nullptr;
        }

        if (node->left != nullptr && to_delete.find(node->left->val) != to_delete.end()) {
            node->left = nullptr;
        }
    }

  public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete)
    {
        std::unordered_set<int> dddd;
        for (const auto i : to_delete) {
            dddd.insert(i);
        }

        std::vector<TreeNode*> nodes;
        delNodesHelper(root, dddd, nodes);

        if (dddd.find(root->val) == dddd.end()) {
            nodes.push_back(root);
        }
        
        return nodes;
    }
};