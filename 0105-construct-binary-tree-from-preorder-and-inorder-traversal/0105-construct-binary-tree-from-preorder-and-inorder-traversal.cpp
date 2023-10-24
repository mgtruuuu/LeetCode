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
    TreeNode* buildTreeHelper(const std::vector<int>& preorder, const std::vector<int>& inorder, const int idx_in_start,
                              const int idx_in_end, const int idx_pre)
    {
        if (idx_in_start == idx_in_end) {
            return new TreeNode{ preorder[idx_pre] };
        }
        else if (idx_in_start > idx_in_end) {
            return nullptr;
        }

        const auto dist =
            std::distance(inorder.begin() + idx_in_start, std::find(inorder.begin(), inorder.end(), preorder[idx_pre]));

        return new TreeNode{
            preorder[idx_pre], buildTreeHelper(preorder, inorder, idx_in_start, idx_in_start + dist - 1, idx_pre + 1),
            buildTreeHelper(preorder, inorder, idx_in_start + dist + 1, idx_in_end, idx_pre + dist + 1)
        };
    }

  public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return buildTreeHelper(preorder, inorder, 0, preorder.size() - 1, 0);
    }
};