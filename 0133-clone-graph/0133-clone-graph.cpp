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

        Node* res;
        Node** pp_curr = &res;

        std::unordered_map<Node*, Node*> hash_visited;

        std::queue<Node*> q;
        q.push(node);

        ////////
        *pp_curr = new Node{ node->val };
        hash_visited[node] = *pp_curr;
        // hash_visited[node] = new Node{ node->val };
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
            }
        }

        return res;
    }
};