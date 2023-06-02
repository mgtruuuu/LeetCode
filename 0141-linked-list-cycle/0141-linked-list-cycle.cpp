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

        auto* fast = head;
        auto* slow = head;

        do {
            for (int i = 0; i != 2; ++i) {
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

// class Solution {
//   public:
//     bool hasCycle(ListNode* head)
//     {
//         if (head == nullptr) {
//             return false;
//         }

//         std::set<ListNode*> nodes;
//         ListNode* next_node = head;

//         do {
//             if (nodes.find(next_node) != nodes.end()) {
//                 return true;
//             }
//             else {

//             }
//         } while (next_node != nullptr);

//         return false;
//     }
// };