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

// Approach 1: Tail Recursion + BFS
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


/*
// Approach 2: Iteration
class Solution {
  public:
    int maxDepth(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }

        std::vector<std::pair<int, TreeNode*>> my_stack;
        my_stack.push_back(std::pair<int, TreeNode*>(1, root));
        auto max_depth = 0;
        while (my_stack.empty() == false) {
            std::pair<int, TreeNode*> my_pair = my_stack.back();
            const auto c_depth = get<0>(my_pair);
            const auto* c_node = get<1>(my_pair);
            if (max_depth < c_depth) {
                max_depth = c_depth;
            }
            my_stack.pop_back();

            if (c_node->left != nullptr) {
                my_stack.push_back(pair<int, TreeNode*>(c_depth + 1, c_node->left));
            }
            if (c_node->right != nullptr) {
                my_stack.push_back(pair<int, TreeNode*>(c_depth + 1, c_node->right));
            }
        }

        return max_depth;
    }
};
*/


/*
// Approach 3: Recursion 
class Solution {
  public:
    int maxDepth(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }

        return std::max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }
};
*/