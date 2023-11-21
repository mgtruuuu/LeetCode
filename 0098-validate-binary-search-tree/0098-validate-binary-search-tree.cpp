/*
// Approach 1: Recursive Traversal with Valid Range
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
*/


/*
// Approach 2: Iterative Traversal with Valid Range
class Solution {
  public:
    bool isValidBST(TreeNode* root)
    {
        using MyNode = std::vector<TreeNode*>;

        std::stack<MyNode> s;
        s.push({root, nullptr, nullptr});
        while (s.empty() == false) {

            const auto node = s.top();
            s.pop();

            if (node[0] == nullptr) {
                continue;
            }

            if (node[1] != nullptr && node[1]->val >= node[0]->val) {
                return false;
            }

            if (node[2] != nullptr && node[0]->val >= node[2]->val) {
                return false;
            }

            s.push({node[0]->right, node[0], node[2]});
            s.push({node[0]->left, node[1], node[0]});
        }

        return true;
    }
};
*/



// Approach 3: Recursive Inorder Traversal
class Solution {
  private:
    std::stack<TreeNode*> s;
    // bool isValidBSTHelper(TreeNode* node, TreeNode* lower_limit = nullptr, TreeNode* upper_limit = nullptr)
    // {
    //     if (node == nullptr) {
    //         return true;
    //     }

    //     if (lower_limit != nullptr && lower_limit->val >= node->val) {
    //         return false;
    //     }

    //     if (upper_limit != nullptr && node->val >= upper_limit->val) {
    //         return false;
    //     }

    //     return isValidBSTHelper(node->left, lower_limit, node) && isValidBSTHelper(node->right, node, upper_limit);
    // }

  public:
    bool isValidBST(TreeNode* root)
    {
        // return isValidBSTHelper(root);
        if (root == nullptr) {
            return true;
        }

        if (isValidBST(root->left) == false) {
            return false;
        }

        if (s.empty() == true) {
            s.push(root);
        }
        else {
            if (s.top()->val < root->val) {
                s.push(root);
            }
            else {
                return false;
            }
        }

        if (isValidBST(root->right) == false) {
            return false;
        }

        return true;
    }
};