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


///*
class Solution {
  public:
    ListNode* swapPairs(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        auto* res = head->next;

        auto dummy = ListNode{};
        auto* prev = &dummy;

        auto* curr = head;
        while (curr != nullptr && curr->next != nullptr) {

            prev->next = curr->next;
            prev = curr;

            curr = curr->next->next;
            prev->next->next = prev;
            prev->next = curr;
        }

        return res;
    }
};
//*/


/*
class Solution {
  public:
    ListNode* swapPairs(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        auto* temp = head->next;

        head->next = swapPairs(head->next->next);

        temp->next = head;
        return temp;
    }
};
*/