class Solution {
  private:
    int longestPath(TreeNode* node, int& diameter)
    {
        if (node == nullptr) {
            return 0;
        }

        auto path_child_left = longestPath(node->left, diameter);
        auto path_child_right = longestPath(node->right, diameter);

        if (diameter < path_child_left + path_child_right) {
            diameter = path_child_left + path_child_right;
        }

        return std::max(path_child_left, path_child_right) + 1;
    }

  public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        auto diameter = 0;
        longestPath(root, diameter);
        return diameter;
    }
};