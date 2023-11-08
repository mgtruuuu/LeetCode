/*
// Approach 1: Recursive Approach
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



///*
// Approach 2: Iterative Approach
class Solution {
  public:
    ListNode* swapPairs(ListNode* head)
    {
        auto dummy = ListNode{ INT_MIN, head };
        auto* prev = &dummy;

        while (head != nullptr && head->next != nullptr) {

            prev->next = head->next;
            prev = head;

            head = head->next->next;
            prev->next->next = prev;
            prev->next = head;
        }

        return dummy.next;
    }
};
//*/



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