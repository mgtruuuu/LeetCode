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
  private:
    ListNode* kkk;
    ListNode* reverseListHelper(ListNode* head)
    {
        if (head->next == nullptr) {

            kkk = head;

            return head;
        }

        auto* node = reverseListHelper(head->next);

        node->next = head;

        head->next = nullptr;

        return head;
    }

  public:
    ListNode* reverseList(ListNode* head)
    {
        if (head == nullptr) {
            return head;
        }

        reverseListHelper(head);

        return kkk;
    }
};