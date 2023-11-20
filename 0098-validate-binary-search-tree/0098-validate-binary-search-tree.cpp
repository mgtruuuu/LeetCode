class Solution {
  private:
    bool isValidBSTHelper(TreeNode* node, TreeNode* lower_limit = nullptr, TreeNode* upper_limit = nullptr)
    {
        if (node == nullptr) {
            return true;
        }

        if (lower_limit != nullptr && lower_limit->val >= node->val) {
            return false;
        }

        if (upper_limit != nullptr && node->val >= upper_limit->val) {
            return false;
        }

        return isValidBSTHelper(node->left, lower_limit, node) && isValidBSTHelper(node->right, node, upper_limit);
    }

  public:
    bool isValidBST(TreeNode* root)
    {
        return isValidBSTHelper(root);
    }
};