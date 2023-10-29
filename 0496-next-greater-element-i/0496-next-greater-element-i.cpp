// Approach 1: Monotinic Stack
class Solution {
  public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        std::unordered_map<int, int> curr_2_next;

        {
            std::stack<int> s;
            
            for (const auto num2 : nums2) {

                while (s.empty() == false && s.top() < num2) {

                    curr_2_next[s.top()] = num2;
                    s.pop();
                }

                s.push(num2);
            }

            while (s.empty() == false) {

                curr_2_next[s.top()] = -1;
                s.pop();
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