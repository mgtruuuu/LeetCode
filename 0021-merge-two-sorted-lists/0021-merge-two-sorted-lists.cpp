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
        if (list1 == nullptr) {
            return list2;
        }

        if (list2 == nullptr) {
            return list1;
        }

        auto* p_list1 = list1;
        auto* p_list2 = list2;
        ListNode* res;

        if (p_list1->val <= p_list2->val) {
            res = p_list1;
            p_list1 = p_list1->next;
        }
        else {
            res = p_list2;
            p_list2 = p_list2->next;
        }

        auto* p_branch = res;

        
        while (true) {
            if (p_list1 == nullptr) {
                p_branch->next = p_list2;

                break;
            }

            if (p_list2 == nullptr) {
                p_branch->next = p_list1;

                break;
            }

            if (p_list1->val <= p_list2->val) {
                p_branch->next = p_list1;
                p_branch = p_branch->next;
                p_list1 = p_list1->next;
            }
            else {
                p_branch->next = p_list2;
                p_branch = p_branch->next;
                p_list2 = p_list2->next;
            }
        }

        return res;
    }
};