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
        std::stack<int> stack_l1;
        std::stack<int> stack_l2;
        std::stack<int> stack_res;

        auto* p_l1 = l1;
        while (p_l1 != nullptr) {
            stack_l1.push(p_l1->val);
            p_l1 = p_l1->next;
        }

        auto* p_l2 = l2;
        while (p_l2 != nullptr) {
            stack_l2.push(p_l2->val);
            p_l2 = p_l2->next;
        }

        auto plus_one = 0;
        while (stack_l1.empty() == false && stack_l2.empty() == false) {

            const auto val1 = stack_l1.top();
            stack_l1.pop();
            const auto val2 = stack_l2.top();
            stack_l2.pop();

            if (val1 + val2 + plus_one > 9) {
                stack_res.push(val1 + val2 + plus_one - 10);
                plus_one = 1;
            }
            else {
                stack_res.push(val1 + val2 + plus_one);
                plus_one = 0;
            }
        }

        if (stack_l1.empty() == true) {
            while (stack_l2.empty() == false) {

                const auto val2 = stack_l2.top();
                stack_l2.pop();

                if (val2 + plus_one > 9) {
                    stack_res.push(val2 + plus_one - 10);
                    plus_one = 1;
                }
                else {
                    stack_res.push(val2 + plus_one);
                    plus_one = 0;
                }
            }
        }
        else {
            while (stack_l1.empty() == false) {

                const auto val1 = stack_l1.top();
                stack_l1.pop();

                if (val1 + plus_one > 9) {
                    stack_res.push(val1 + plus_one - 10);
                    plus_one = 1;
                }
                else {
                    stack_res.push(val1 + plus_one);
                    plus_one = 0;
                }
            }
        }

        if (plus_one == 1) {
            stack_res.push(plus_one);
        }

        ListNode* p_res = nullptr;
        auto** pptr = &p_res;

        while (stack_res.empty() == false) {
            *pptr = new ListNode{ stack_res.top() };
            pptr = &(*pptr)->next;

            stack_res.pop();
        }

        return p_res;
    }
};