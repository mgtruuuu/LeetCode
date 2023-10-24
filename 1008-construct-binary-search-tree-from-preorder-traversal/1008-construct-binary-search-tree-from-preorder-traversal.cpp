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
// Approach 1: Construct binary tree from preorder and inorder traversal
class Solution {
  private:
    TreeNode* buildTreeHelper(const std::vector<int>& preorder, const std::unordered_map<int, int>& inorderNode2idx,
                              const int idx_in_start, const int idx_in_end, const int idx_pre)
    {
        if (idx_in_start == idx_in_end) {
            return new TreeNode{ preorder[idx_pre] };
        }
        else if (idx_in_start > idx_in_end) {
            return nullptr;
        }

        const auto dist = inorderNode2idx.at(preorder[idx_pre]) - idx_in_start;

        return new TreeNode{
            preorder[idx_pre],
            buildTreeHelper(preorder, inorderNode2idx, idx_in_start, idx_in_start + dist - 1, idx_pre + 1),
            buildTreeHelper(preorder, inorderNode2idx, idx_in_start + dist + 1, idx_in_end, idx_pre + dist + 1)
        };
    }

  public:
    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        auto inorder = preorder;
        std::sort(inorder.begin(), inorder.end());

        std::unordered_map<int, int> inorderNode2idx;
        for (auto idx = 0; idx != static_cast<int>(inorder.size()); ++idx) {
            inorderNode2idx[inorder[idx]] = idx;
        }

        return buildTreeHelper(preorder, inorderNode2idx, 0, preorder.size() - 1, 0);
    }
};
*/


///*
// Approach 2: Recursion
class Solution {
  private:
    TreeNode* buildTreeHelper(const std::vector<int>& preorder, const int idx_in_start, const int idx_in_end)
    {
        if (idx_in_start > idx_in_end) {
            return nullptr;
        }

        const auto parent = preorder[idx_in_start];
        const auto idx_new = std::distance(
            preorder.begin(), std::find_if(preorder.begin() + idx_in_start + 1, preorder.end(),
                                           [parent](int node_preorder) { return parent < node_preorder; }));

        return new TreeNode{ parent, buildTreeHelper(preorder, idx_in_start + 1, idx_new - 1),
                             buildTreeHelper(preorder, idx_new, idx_in_end) };
    }

  public:
    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        return buildTreeHelper(preorder, 0, preorder.size() - 1);
    }
};
//*/