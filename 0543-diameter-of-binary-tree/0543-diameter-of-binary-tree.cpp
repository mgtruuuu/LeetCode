class Solution {
  private:
    int getHeight(TreeNode* node, int& diameter)
    {
        if (node == nullptr) {
            return 0;
        }

        auto height_left = getHeight(node->left, diameter);
        auto height_right = getHeight(node->right, diameter);

        if (diameter < height_left + height_right) {
            diameter = height_left + height_right;
        }

        return std::max(height_left, height_right) + 1;
    }

  public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        auto diameter = 0;
        getHeight(root, diameter);
        return diameter;
    }
};