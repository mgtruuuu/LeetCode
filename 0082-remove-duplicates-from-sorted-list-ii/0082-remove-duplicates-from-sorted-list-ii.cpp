/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
  public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        auto* sentinel = new ListNode{ 0, head };

        auto* prev = sentinel;
        auto* curr = sentinel->next;

        while (curr != nullptr) {

            if (curr->next != nullptr && curr->val == curr->next->val) {

                do {

                    auto* temp = curr->next;
                    // delete curr;
                    curr = temp;

                } while (curr->next != nullptr && curr->val == curr->next->val);

                auto* temp = curr->next;
                // delete curr;
                prev->next = temp;
            }
            else {
                prev = prev->next;
            }

            curr = curr->next;
        }

        auto* res = sentinel->next;

        delete sentinel;
        sentinel = nullptr;
        return res;
    }
};