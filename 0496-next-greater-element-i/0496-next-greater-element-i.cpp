// Approach 1: Using Stack
class Solution {
  public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        std::unordered_map<int, int> curr_2_next;

        {
            std::stack<int> monotinic_stack;
            for (auto idx = std::size_t(0); idx != nums2.size(); ++idx) {

                while (monotinic_stack.empty() == false && monotinic_stack.top() < nums2[idx]) {

                    curr_2_next[monotinic_stack.top()] = nums2[idx];
                    monotinic_stack.pop();
                }

                monotinic_stack.push(nums2[idx]);
            }

            while (monotinic_stack.empty() == false) {

                curr_2_next[monotinic_stack.top()] = -1;
                monotinic_stack.pop();
            }
        }

        std::vector<int> res;
        res.reserve(nums1.size());
        for (const auto num1 : nums1) {
            res.push_back(curr_2_next[num1]);
        }

        return res;
    }
};