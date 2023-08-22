/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> levelOrder(Node* root)
    {
        std::queue<Node*> q;

        if (root == nullptr) {
            return {};
        }
        

        std::vector<std::vector<int>> res;

        q.push(root);        

        while (true) {

            std::vector<int> vals_same_level;

            auto len_q = q.size();
            
            while (len_q-- != 0) {

                auto* node = q.front();
                q.pop();

                vals_same_level.push_back(node->val);
                for (auto* child : node->children) {
                    q.push(child);
                }
            }

            res.push_back(vals_same_level);
            
            if (q.empty() == true) {
                return res;
            }
        }

        return res; // Never be reached
    }
};