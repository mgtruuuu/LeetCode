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
// Approach 1 - 1: Recursion
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


///*
// Approach 1 - 2: Recursion <----- optimized but is it really faster?
class Solution {
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

                TreeNode* min_node = root->right;
                TreeNode* second_min_node = root;

                while (min_node->left != nullptr) {

                    second_min_node = min_node;
                    min_node = min_node->left;
                } 

                root->val = min_node->val;

                if (second_min_node == root) {
                    second_min_node->right = deleteNode(second_min_node->right, root->val);    
                }
                else {
                    second_min_node->left = deleteNode(second_min_node->left, root->val);    
                }
            }
        }

        return root;
    }
};

//*/