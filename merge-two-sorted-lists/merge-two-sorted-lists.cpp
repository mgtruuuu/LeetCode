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

/*
// Approach 1: Recursion
class Solution {
  public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (list1 == nullptr) {
            return list2;
        }
        else if (list2 == nullptr) {
            return list1;
        }

        // method 1
        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }


        // method 2
        ListNode** ppLeftArgs = &list1;
        ListNode** ppRightArgs = &list2;
        ListNode** ppReturn;
        if (list1->val < list2->val) {
            ppReturn = ppLeftArgs;
            ppLeftArgs = &list1->next;
        }
        else {
            ppReturn = ppRightArgs;
            ppRightArgs = &list2->next;
        }

        (*ppReturn)->next = mergeTwoLists(*ppLeftArgs, *ppRightArgs);
        return *ppReturn;

    }
};
*/
    
///*
// Approach 2: Iteration
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

        list1 == nullptr ? * ppNode = list2 : * ppNode = list1;

        return pMerged;
    }
};
//*/