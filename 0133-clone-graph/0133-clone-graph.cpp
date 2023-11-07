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
        if (node_src == nullptr) {
            return nullptr;
        }

        if (src2dst.find(node_src) != src2dst.end()) {
            return src2dst[node_src];
        }

        src2dst[node_src] = new Node{ node_src->val };

        for (auto* neighbor_src : node_src->neighbors) {
            src2dst[node_src]->neighbors.push_back(cloneGraphHelper(neighbor_src, src2dst));
        }
        return src2dst[node_src];
    }

  public:
    Node* cloneGraph(Node* node)
    {
        std::unordered_map<Node*, Node*> src2dst;

        return cloneGraphHelper(node, src2dst);
    }
};