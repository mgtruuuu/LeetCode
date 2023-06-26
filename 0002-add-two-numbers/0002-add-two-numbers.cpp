class Solution {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        auto* p_l1 = l1;
        auto* p_l2 = l2;

        ListNode* p_res = nullptr;
        ListNode** pp_res = &p_res;

        auto plus_one = 0;
        while (p_l1 != nullptr && p_l2 != nullptr) {

            *pp_res = new ListNode{};

            if (p_l1->val + p_l2->val + plus_one > 9) {
                (*pp_res)->val = p_l1->val + p_l2->val + plus_one - 10;
                plus_one = 1;
            }
            else {
                (*pp_res)->val = p_l1->val + p_l2->val + plus_one;
                plus_one = 0;
            }

            p_l1 = p_l1->next;
            p_l2 = p_l2->next;
            pp_res = &(*pp_res)->next;
        }

        if (p_l1 == nullptr) {
            while (p_l2 != nullptr) {

                *pp_res = new ListNode{};

                if (p_l2->val + plus_one > 9) {
                    (*pp_res)->val = p_l2->val + plus_one - 10;
                    plus_one = 1;
                }
                else {
                    (*pp_res)->val = p_l2->val + plus_one;
                    plus_one = 0;
                }

                p_l2 = p_l2->next;
                pp_res = &(*pp_res)->next;
            }
        }
        else {
            while (p_l1 != nullptr) {

                *pp_res = new ListNode{};

                if (p_l1->val + plus_one > 9) {
                    (*pp_res)->val = p_l1->val + plus_one - 10;
                    plus_one = 1;
                }
                else {
                    (*pp_res)->val = p_l1->val + plus_one;
                    plus_one = 0;
                }

                p_l1 = p_l1->next;
                pp_res = &(*pp_res)->next;
            }
        }

        if (plus_one == 1) {
            *pp_res = new ListNode{};
            (*pp_res)->val = plus_one;
            (*pp_res)->next = nullptr;
        }

        return p_res;
    }
};