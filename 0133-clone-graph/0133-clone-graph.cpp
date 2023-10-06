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
    std::unordered_map<Node*, Node*> hash_visited;

  public:
    Node* cloneGraph(Node* node)
    {
        if (node == nullptr) {
            return node;
        }

        if (hash_visited.find(node) != hash_visited.end()) {
            return hash_visited[node];
        }
        
        Node* clone_node = new Node{ node->val };
        hash_visited[node] = clone_node;

        for (Node* neighbor : node->neighbors) {
            clone_node->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone_node;
    }
};



/*
// Approach 2: Iterative BFS
class Solution {
  public:
    Node* cloneGraph(Node* node)
    {
        if (node == nullptr) {
            return nullptr;
        }

        Node* res;
        Node** pp_curr = &res;

        std::unordered_map<Node*, Node*> hash_visited;

        std::queue<Node*> q;
        q.push(node);

        ////////
        hash_visited[node] = new Node{ node->val };
        *pp_curr = hash_visited[node];
        ////////

        while (q.empty() == false) {

            Node* curr = q.front();
            q.pop();

            ////////
            pp_curr = &hash_visited[curr];
            (**pp_curr).neighbors.reserve(curr->neighbors.size());
            ////////

            for (Node* child : curr->neighbors) {

                if (hash_visited.find(child) == hash_visited.end()) {

                    q.push(child);

                    ////////
                    hash_visited[child] = new Node{ child->val };
                    ////////
                }

                ////////
                (**pp_curr).neighbors.push_back(hash_visited[child]);
                ////////
            }
        }

        return res;
    }
};
*/