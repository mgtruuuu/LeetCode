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
    ListNode* swapPairs(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        auto* res = head->next;

        ListNode* prev = new ListNode{};
        ListNode* to_delete = prev;
        auto* curr = head;

        while (curr != nullptr && curr->next != nullptr) {

            // prev->next = prev->next;
            // prev = curr;

            prev->next = curr->next;
            prev = curr;

            auto* temp = curr->next->next;
            curr->next->next = curr;
            curr = curr->next;
            curr->next->next = temp;
            curr = temp;
        }

        delete to_delete;
        return res;
    }
};
