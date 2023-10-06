/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
  public:
    Node* copyRandomList(Node* head)
    {
        if (head == nullptr) {
            return nullptr;
        }
        
        std::unordered_map<Node*, Node*> hash_visited;
        
        Node* res = new Node{ head->val };
        hash_visited[head] = res;
        Node* curr = res;
        head = head->next;
        
        while (head != nullptr) {
            
            curr->next = new Node{ head->val };
            curr = curr->next;
            hash_visited[head] = curr;
            
            head = head->next;
        }
        
        curr->next = nullptr;
        
        for (auto& [k, v] : hash_visited) {
            v->random = (k->random == nullptr) ? nullptr : hash_visited[k->random];
        }
        
        return res;
    }
};