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
  public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        if (nums.size() == 1) {
            return new TreeNode{ nums.front() };
        }
        else if (nums.size() == 2) {
            return new TreeNode{ nums.back(), new TreeNode{ nums.front() }, nullptr };
        }

        const auto idx = nums.size() / 2;

        std::vector<int> left(nums.begin(), nums.begin() + idx);
        std::vector<int> right(nums.begin() + idx + 1, nums.end());
        return new TreeNode{ nums[idx], sortedArrayToBST(left), sortedArrayToBST(right) };
    }
};