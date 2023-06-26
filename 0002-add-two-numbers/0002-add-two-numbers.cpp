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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        auto* p_l1 = l1;
        auto* p_l2 = l2;

        ListNode* res = new ListNode{};
        auto* p_res = res;
        ListNode* p_res_prev = nullptr;

        auto plus_one = 0;
        while (p_l1 != nullptr && p_l2 != nullptr) {

            if (p_l1->val + p_l2->val + plus_one > 9) {
                p_res->val = p_l1->val + p_l2->val + plus_one - 10;
                plus_one = 1;
            }
            else {
                p_res->val = p_l1->val + p_l2->val + plus_one;
                plus_one = 0;
            }

            p_l1 = p_l1->next;
            p_l2 = p_l2->next;
            p_res_prev = p_res;
            p_res->next = new ListNode{};
            p_res = p_res->next;
        }

        if (p_l1 == nullptr) {
            while (p_l2 != nullptr) {

                if (p_l2->val + plus_one > 9) {
                    p_res->val = p_l2->val + plus_one - 10;
                    plus_one = 1;
                }
                else {
                    p_res->val = p_l2->val + plus_one;
                    plus_one = 0;
                }

                p_l2 = p_l2->next;
                p_res_prev = p_res;
                p_res->next = new ListNode{};
                p_res = p_res->next;
            }
        }
        else {
            while (p_l1 != nullptr) {

                if (p_l1->val + plus_one > 9) {
                    p_res->val = p_l1->val + plus_one - 10;
                    plus_one = 1;
                }
                else {
                    p_res->val = p_l1->val + plus_one;
                    plus_one = 0;
                }

                p_l1 = p_l1->next;
                p_res_prev = p_res;
                p_res->next = new ListNode{};
                p_res = p_res->next;
            }
        }

        if (plus_one == 1) {
            p_res->val = plus_one;
            p_res->next = nullptr;
        }
        else {
            delete p_res;
            p_res_prev->next = nullptr;            
        }
        
        return res;
    }
};