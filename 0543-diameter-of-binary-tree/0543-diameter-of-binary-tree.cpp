class Solution {
  private:
    int getHeightAndDiameter(TreeNode* node, int& diameter)
    {
        if (node == nullptr) {
            return 0;
        }

        const auto height_left = getHeightAndDiameter(node->left, diameter);
        const auto height_right = getHeightAndDiameter(node->right, diameter);

        if (diameter < height_left + height_right) {
            diameter = height_left + height_right;
        }

        return std::max(height_left, height_right) + 1;
    }

  public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        auto diameter = 0;
        getHeightAndDiameter(root, diameter);
        return diameter;
    }
};