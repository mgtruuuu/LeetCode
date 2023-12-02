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


/*
class Solution {
  private:
    void preorderHelper(Node* node, std::vector<int>& vals)
    {
        if (node == nullptr) {
            return;
        }

        vals.push_back(node->val);
        for (auto* neighbor : node->children) {
            preorderHelper(neighbor, vals);
        }
    }

  public:
    vector<int> preorder(Node* root)
    {
        std::vector<int> vals;
        preorderHelper(root, vals);

        return vals;
    }
};
*/


class Solution {
  public:
    vector<int> preorder(Node* root)
    {
        std::vector<int> vals;

        std::stack<Node*> s;
        s.push(root);

        while (s.empty() == false) {

            auto* node = s.top();
            s.pop();
            
            if (node == nullptr) {
                continue;
            }

            vals.push_back(node->val);

            for (auto idx = node->children.size(); idx-- != 0;) {
                s.push(node->children[idx]);
            }
        }

        return vals;
    }
};