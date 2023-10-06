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
        std::unordered_map<Node*, Node*> hash_visited;

        Node* res = nullptr;
        Node** pp_dst = &res;
        
        while (head != nullptr) {
            
            *pp_dst = new Node{ head->val };
            
            hash_visited[head] = *pp_dst;    
            
            pp_dst = &((**pp_dst).next);
            
            head = head->next;
        }
        
        *pp_dst = nullptr;
        
        for (auto& [k, v] : hash_visited) {
            v->random = (k->random == nullptr) ? nullptr : hash_visited[k->random];
        }
        
        return res;
    }
};