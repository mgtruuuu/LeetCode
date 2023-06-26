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
    ListNode* reverseList(ListNode* head)
    {
        if (head == nullptr) {
            return nullptr;
        }

        auto* node_new_next = head;
        auto* node_new = node_new_next->next;
        node_new_next->next = nullptr;

        while (node_new != nullptr) {
            auto* temp = node_new;
            node_new = node_new->next;
            temp->next = node_new_next;
            node_new_next = temp;
        }

        return node_new_next;
    }
};
