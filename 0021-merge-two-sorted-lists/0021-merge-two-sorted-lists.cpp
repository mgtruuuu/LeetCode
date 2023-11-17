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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* pMerged;
        ListNode** ppNode = &pMerged;
        while (list1 != nullptr && list2 != nullptr) {

            if (list1->val < list2->val) {
                *ppNode = list1;
                list1 = list1->next;
            }
            else {
                *ppNode = list2;
                list2 = list2->next;
            }

            ppNode = &(*ppNode)->next;
        }

        if (list1 == nullptr) {
            *ppNode = list2;
        }
        else {
            *ppNode = list1;
        }

        return pMerged;
    }
};