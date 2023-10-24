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
//
class Solution {
  private:
    TreeNode* minKeyNode(TreeNode* node)
    {
        while (node->left != nullptr) {
            node = node->left;
        }

        return node;
    }

  public:
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if (root == nullptr) {
            return nullptr;
        }

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {

            TreeNode* temp = root;

            if (root->left == nullptr) {

                root = root->right;
                delete temp;
            }
            else if (root->right == nullptr) {

                root = root->left;
                delete temp;
            }
            else {

                root->val = minKeyNode(root->right)->val;
                root->right = deleteNode(root->right, root->val);
            }
        }

        return root;
    }
};
*/


//
class Solution {
  private:
    TreeNode* secondMinKeyNode(TreeNode* node)
    {
        while (node->left->left != nullptr) {
            node = node->left;
        }

        return node;
    }

  public:
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if (root == nullptr) {
            return nullptr;
        }

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {

            TreeNode* temp = root;

            if (root->left == nullptr) {

                root = root->right;
                delete temp;
            }
            else if (root->right == nullptr) {

                root = root->left;
                delete temp;
            }
            else if (root->right->left == nullptr) {

                root->val = root->right->val;
                root->right = deleteNode(root->right, root->val);
            }
            else {

                root->val = secondMinKeyNode(root->right)->left->val;
                root->right = deleteNode(root->right, root->val);
            }
        }

        return root;
    }
};