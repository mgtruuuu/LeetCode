/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    bool hasCycle(ListNode* head)
    {
        if (head == nullptr) {
            return false;
        }
        
        std::set<ListNode*> nodes;

        nodes.insert(head);
        auto* next_node = head->next;
        while (next_node != nullptr) {

            if (nodes.find(next_node) != nodes.end()) {
                return true;
            }
            else {
                nodes.insert(next_node);
                next_node = next_node->next;
            }
        }

        return false;
    }
};