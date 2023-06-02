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
            // fast = fast->next->next;

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

