class Solution {
  public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* pNode;
        ListNode** ppNode = &pNode;

        while (list1 != nullptr && list2 != nullptr) {

            if (list1->val < list2->val) {
                *ppNode = list1;
                list1 = list1->next;

                ppNode = &(**ppNode).next;
            }
            else {
                *ppNode = list2;
                list2 = list2->next;

                ppNode = &(**ppNode).next;
            }
        }

        if (list1 == nullptr) {
            *ppNode = list2;
        }

        if (list2 == nullptr) {
            *ppNode = list1;
        }

        return pNode;
    }
};