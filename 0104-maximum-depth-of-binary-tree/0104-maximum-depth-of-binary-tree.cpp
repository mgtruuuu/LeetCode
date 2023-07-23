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
    // The queue that contains the next nodes to visit,
    // along with the level/depth that each node is located.
    std::queue<std::pair<TreeNode*, int>> next_items;
    int max_depth = 0;

    // A tail recursion function to calculate the max depth of the binary tree.
    int next_maxDepth()
    {
        if (next_items.empty() == true) {
            return max_depth;
        }

        const auto next_item = next_items.front();
        next_items.pop();

        const auto next_node = next_item.first;
        const auto next_level = next_item.second + 1;

        if (max_depth < next_level) {
            max_depth = next_level;
        }

        // Add the nodes to visit in the following recursive calls.
        if (next_node->left != nullptr) {
            next_items.push(std::make_pair(next_node->left, next_level));
        }
        if (next_node->right != nullptr) {
            next_items.push(std::make_pair(next_node->right, next_level));
        }

        // The last action should be the ONLY recursive call in the tail-recursion function.
        return next_maxDepth();
    }

  public:
    int maxDepth(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }

        // Clear the previous queue.
        std::queue<pair<TreeNode*, int>> empty;
        std::swap(next_items, empty);
        max_depth = 0;

        // Push the root node into the queue to kick off the next visit.
        next_items.push(std::make_pair(root, 0));

        return next_maxDepth();
    }
};