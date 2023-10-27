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
        std::set<ListNode*> nodes;
        
        while (head != nullptr) {

            if (nodes.find(head) != nodes.end()) {
                return true;
            }
            
            nodes.insert(head);
            
            head = head->next;
        }

        return false;
    }
};

/*
// Approach 2: Floyd's Cycle Finding Algorithm
class Solution {
  public:
    bool hasCycle(ListNode* head)
    {
        if (head == nullptr) {
            return false;
        }

        const auto* fast = head;
        const auto* slow = head;

        constexpr auto n_fast = 2;

        do {
            for (auto i = 0; i != n_fast; ++i) {
                fast = fast->next;
                if (fast == nullptr) {
                    return false;
                }
            }

            slow = slow->next;

        } while (fast != slow);

        return true;
    }
};
*/