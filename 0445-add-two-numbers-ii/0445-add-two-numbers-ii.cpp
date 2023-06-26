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

        ListNode* child = nullptr;

        auto plus_one = 0;
        auto digit = 0;
        while (stack_l1.empty() == false && stack_l2.empty() == false) {

            const auto val1 = stack_l1.top();
            stack_l1.pop();
            const auto val2 = stack_l2.top();
            stack_l2.pop();

            if (val1 + val2 + plus_one > 9) {
                digit = val1 + val2 + plus_one - 10;
                plus_one = 1;
            }
            else {
                digit = val1 + val2 + plus_one;
                plus_one = 0;
            }

            child = new ListNode{ digit, child };
        }

        if (stack_l1.empty() == true) {
            while (stack_l2.empty() == false) {

                const auto val2 = stack_l2.top();
                stack_l2.pop();

                if (val2 + plus_one > 9) {
                    digit = val2 + plus_one - 10;
                    plus_one = 1;
                }
                else {
                    digit = val2 + plus_one;
                    plus_one = 0;
                }

                child = new ListNode{ digit, child };
            }
        }
        else {
            while (stack_l1.empty() == false) {

                const auto val1 = stack_l1.top();
                stack_l1.pop();

                if (val1 + plus_one > 9) {
                    digit = val1 + plus_one - 10;
                    plus_one = 1;
                }
                else {
                    digit = val1 + plus_one;
                    plus_one = 0;
                }

                child = new ListNode{ digit, child };
            }
        }

        if (plus_one == 1) {
            child = new ListNode{ plus_one, child };
        }

        return child;
    }
};