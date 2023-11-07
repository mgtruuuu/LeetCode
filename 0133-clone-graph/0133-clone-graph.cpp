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

/*
// Approach 1-1: Recursive DFS
class Solution {
  private:
    Node* cloneGraphHelper(Node* node_src, std::unordered_map<Node*, Node*>& src2dst)
    {
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
        return node == nullptr ? nullptr : cloneGraphHelper(node, src2dst);
    }
};
*/



/*
// Approach 1-2: Recursive DFS
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
        std::unordered_map<Node*, Node*> src2dst;
        return node == nullptr ? nullptr : cloneGraphHelper(node, src2dst);
    }
};
*/



/*
// Approach 2-1: Iterative DFS
class Solution {
  public:
    Node* cloneGraph(Node* node)
    {
        if (node == nullptr) {
            return nullptr;
        }

        std::stack<Node*> s;
        std::unordered_map<Node*, Node*> src2dst;

        s.push(node);
        src2dst[node] = new Node{ node->val };

        while (s.empty() == false) {

            auto* node_src = s.top();
            auto* node_dst = src2dst[node_src];
            s.pop();

            node_dst->neighbors.reserve(node_src->neighbors.size());

            for (auto* neighbor_src : node_src->neighbors) {

                if (src2dst.find(neighbor_src) == src2dst.end()) {
                    src2dst[neighbor_src] = new Node{ neighbor_src->val };

                    s.push(neighbor_src);
                }

                node_dst->neighbors.push_back(src2dst[neighbor_src]);
            }
        }

        return src2dst[node];
    }
};
*/


/*
// Approach 2-2: Iterative DFS
class Solution {
  public:
    Node* cloneGraph(Node* node)
    {
        if (node == nullptr) {
            return nullptr;
        }

        std::stack<Node*> s;
        std::unordered_map<Node*, Node*> src2dst;
        std::unordered_set<Node*> seen;

        s.push(node);
        src2dst[node] = new Node{ node->val };

        while (s.empty() == false) {

            auto* node_src = s.top();
            auto* node_dst = src2dst[node_src];
            s.pop();

            if (seen.find(node_src) != seen.end()) {
                continue;
            }
            seen.insert(node_src);

            node_dst->neighbors.reserve(node_src->neighbors.size());

            for (auto* neighbor_src : node_src->neighbors) {

                if (src2dst.find(neighbor_src) == src2dst.end()) {
                    src2dst[neighbor_src] = new Node{ neighbor_src->val };
                }

                node_dst->neighbors.push_back(src2dst[neighbor_src]);
                s.push(neighbor_src);
            }
        }

        return src2dst[node];
    }
};
*/



///*
// Approach 3-1: Iterative BFS
class Solution {
  public:
    Node* cloneGraph(Node* node)
    {
        if (node == nullptr) {
            return nullptr;
        }

        std::queue<Node*> q;
        std::unordered_map<Node*, Node*> src2dst;

        q.push(node);
        src2dst[node] = new Node{ node->val };

        while (q.empty() == false) {

            auto* node_src = q.front();
            auto* node_dst = src2dst[node_src];
            q.pop();

            node_dst->neighbors.reserve(node_src->neighbors.size());

            for (auto* neighbor_src : node_src->neighbors) {

                if (src2dst.find(neighbor_src) == src2dst.end()) {
                    src2dst[neighbor_src] = new Node{ neighbor_src->val };

                    q.push(neighbor_src);
                }

                node_dst->neighbors.push_back(src2dst[neighbor_src]);
            }
        }

        return src2dst[node];
    }
};
//*/



// Approach 3-2: Iterative BFS