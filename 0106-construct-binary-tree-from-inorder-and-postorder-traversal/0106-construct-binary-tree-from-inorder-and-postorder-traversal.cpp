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
    TreeNode* buildTreeHelper(const std::vector<int>& postorder, const std::unordered_map<int, int>& inorder_node_2_idx,
                              const int idx_in_start, const int idx_in_end, const int idx_post)
    {
        if (idx_in_start > idx_in_end) {
            return nullptr;
        }
        else if (idx_in_start == idx_in_end) {
            return new TreeNode{ postorder[idx_post] };
        }

        const auto idx_in_middle = inorder_node_2_idx.at(postorder[idx_post]);
        const auto dist = idx_in_end - idx_in_middle;
        
        
        TreeNode* node = new TreeNode{ postorder[idx_post] };
        node->left = buildTreeHelper(postorder, inorder_node_2_idx, idx_in_start, idx_in_middle - 1, idx_post - 1 - dist);
        node->right = buildTreeHelper(postorder, inorder_node_2_idx, idx_in_middle + 1, idx_in_end, idx_post - 1);

        return node;
    }

  public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        std::unordered_map<int, int> inorder_node_2_idx;
        for (auto idx = 0; idx != static_cast<int>(inorder.size()); ++idx) {
            inorder_node_2_idx[inorder[idx]] = idx;
        }

        return buildTreeHelper(postorder, inorder_node_2_idx, 0, postorder.size() - 1, postorder.size() - 1);
    }
};