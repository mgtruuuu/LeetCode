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
// Approach 1: Preorder Traversal: Always Choose Left Middle Node as a Root
class Solution {
  private:
    TreeNode* sortedArrayToBSTHelper(const std::vector<int>& nums, const int idx_start, const int idx_end)
    {
        if (idx_start > idx_end) {
            return nullptr;
        }
        else if (idx_start == idx_end) {
            return new TreeNode{ nums[idx_start] };
        }

        const auto idx_middle_left = (idx_start + idx_end) / 2;
        auto* res = new TreeNode{ nums[idx_middle_left] };
        res->left = sortedArrayToBSTHelper(nums, idx_start, idx_middle_left - 1);
        res->right = sortedArrayToBSTHelper(nums, idx_middle_left + 1, idx_end);

        return res;
    }

  public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
    }
};
*/


// Approach 2: Approach 2: Preorder Traversal: Always Choose Right Middle Node as a Root
class Solution {
  private:
    TreeNode* sortedArrayToBSTHelper(const std::vector<int>& nums, const int idx_start, const int idx_end)
    {
        if (idx_start > idx_end) {
            return nullptr;
        }

        const auto idx_middle_left = (idx_start + idx_end + 1) / 2;
        auto* res = new TreeNode{ nums[idx_middle_left] };
        res->left = sortedArrayToBSTHelper(nums, idx_start, idx_middle_left - 1);
        res->right = sortedArrayToBSTHelper(nums, idx_middle_left + 1, idx_end);

        return res;
    }

  public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
    }
};