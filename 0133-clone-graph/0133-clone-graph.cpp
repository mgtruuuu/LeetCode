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

class Solution {
  public:
    Node* cloneGraph(Node* node)
    {
        if (node == nullptr) {
            return nullptr;
        }

        std::stack<Node*> s_src;
        std::unordered_map<Node*, Node*> src2dst;

        s_src.push(node);
        src2dst[node] = new Node{ node->val };

        while (s_src.empty() == false) {

            auto* node_src = s_src.top();
            auto* node_dst = src2dst[node_src];
            s_src.pop();

            node_dst->neighbors.reserve(node_src->neighbors.size());

            for (auto* neighbor_src : node_src->neighbors) {

                if (src2dst.find(neighbor_src) == src2dst.end()) {
                    src2dst[neighbor_src] = new Node{ neighbor_src->val };

                    s_src.push(neighbor_src);
                }

                node_dst->neighbors.push_back(src2dst[neighbor_src]);
            }
        }

        return src2dst[node];
    }
};