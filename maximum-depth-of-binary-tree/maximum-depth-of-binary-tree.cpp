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
// Approach 1: Recursion
// TC: O(N)
// SC: worst O(N), best O(log(N))
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



/*
// Approach 2-1: Tail Recursion + BFS
// TC: O(N)
// SP: the maximum number of nodes at the same level
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

        auto* next_node = next_item.first;
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
*/



///*
// Approach 2-2: Tail Recursion + BFS
// TC: O(N)
// SP: the maximum number of nodes at the same level
class Solution {
  public:
    int maxDepth(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }

        std::queue<TreeNode*> q;
        q.push(root);
        auto max_depth = 0;

        while (q.empty() == false) {

            ++max_depth;
            auto len_q = q.size();

            while (len_q-- != 0) {
                const auto* node = q.front();
                q.pop();

                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        }

        return max_depth;
    }
};
//*/



/*
// Approach 3-1: Iteration
// TC: O(N)
// SC: worst O(N), best O(log(N))
class Solution {
  public:
    int maxDepth(TreeNode* root)
    {
        std::stack<TreeNode*> s1;
        std::stack<TreeNode*> s2;
        
        std::unordered_map<TreeNode*, int> node2depth;

        TreeNode* node;
        s1.push(root);
        while (s1.empty() == false) {

            node = s1.top();
            s1.pop();

            if (node == nullptr) {
                continue;
            }

            s2.push(node);

            s1.push(node->left);
            s1.push(node->right);
        }

        while (s2.empty() == false) {

            node = s2.top();
            s2.pop();

            std::cout << node->val << " ";

            auto depth = 1;
            if (node->left != nullptr && depth < node2depth[node->left] + 1) {
                depth = node2depth[node->left] + 1;
            }
            if (node->right != nullptr && depth < node2depth[node->right] + 1) {
                depth = node2depth[node->right] + 1;
            }

            node2depth[node] = depth;
        }

        return node2depth[root];
    }
};
*/


/*
// Approach 3-2: Iteration
// TC: O(N)
// SC: worst O(N), best O(log(N))
class Solution {
  public:
    int maxDepth(TreeNode* root)
    {
        std::unordered_map<TreeNode*, int> node2depth;

        std::stack<TreeNode*> s;

        TreeNode* curr = root;
        TreeNode* prev;
        while (true) {

            while (curr != nullptr) {

                s.push(curr);

                curr = curr->left;
            }

            if (s.empty() == true) {
                break;
            }
            curr = s.top();

            if (curr->right != nullptr && curr->right != prev) {
                curr = curr->right;
            }
            else {

                s.pop();

                auto depth = 1;
                if (curr->left != nullptr && depth < node2depth[curr->left] + 1) {
                    depth = node2depth[curr->left] + 1;
                }
                if (curr->right != nullptr && depth < node2depth[curr->right] + 1) {
                    depth = node2depth[curr->right] + 1;
                }

                node2depth[curr] = depth;

                prev = curr;
                curr = nullptr;
            }
        }

        return node2depth[root];
    }
};
*/