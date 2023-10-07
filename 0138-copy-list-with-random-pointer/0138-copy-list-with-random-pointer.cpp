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

/*
// Approach 1: Recursive
class Solution {
  private:
    std::unordered_map<Node*, Node*> hash_visited;

  public:
    Node* copyRandomList(Node* head)
    {
        if (head == nullptr) {
            return nullptr;
        }

        Node* node = new Node{ head->val };
        hash_visited[head] = node;
        node->next = copyRandomList(head->next);
        node->random = (head->random == nullptr ? nullptr : hash_visited[head->random]);

        return node;
    }
};
*/


///*
// Approach 2: Iterative with O(N) Space
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
//*/


/*
// Approach 3: Iterative with O(1) Space
class Solution {
  public:
    Node* copyRandomList(Node* head)
    {
        if (head == nullptr) {
            return nullptr;
        }
        
        Node* curr = head;
        while (curr != nullptr) {

            Node* temp = curr->next;

            curr->next = new Node{ curr->val };

            curr->next->next = temp;
            curr = temp;
        }

        curr = head;
        while (curr != nullptr) {

            curr->next->random = (curr->random == nullptr) ? nullptr : curr->random->next;
            curr = curr->next->next;
        }
        
        Node* res = head->next;
        while (head != nullptr) {
             
            Node* temp_copy = head->next;
            Node* temp_next = temp_copy->next;
            temp_copy->next = (temp_next == nullptr ? nullptr : temp_next->next);
            head->next = temp_next;
            
            head = temp_next;
        }
        
        return res;
    }
};
*/