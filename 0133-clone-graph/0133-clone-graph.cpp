/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// Approach 1: Recursive DFS
class Solution {
  private:
    Node* cloneGraphHelper(Node* node_src, std::unordered_map<Node*, Node*>& src2dst)
    {
        src2dst[node_src] = new Node{ node_src->val };

        for (auto* neighbor_src : node_src->neighbors) {

            if (src2dst.find(neighbor_src) == src2dst.end()) {
                src2dst[neighbor_src] = cloneGraphHelper(neighbor_src, src2dst);
            }

            src2dst[node_src]->neighbors.push_back(src2dst[neighbor_src]);
        }

        return src2dst[node_src];
    }

  public:
    Node* cloneGraph(Node* node)
    {
        if (node == nullptr) {
            return nullptr;
        }

        std::unordered_map<Node*, Node*> src2dst;
        return cloneGraphHelper(node, src2dst);
    }
};