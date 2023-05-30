class Solution {
public:
    
    void recursive(const std::vector<int>& nums, const std::size_t idx, std::vector<int>& sub,
                      std::vector<std::vector<int>>& list_sub)
    {
        if (idx == nums.size()) {
            list_sub.push_back(sub);

            return;
        }

        recursive(nums, idx + 1, sub, list_sub);

        sub.push_back(nums[idx]);
        recursive(nums, idx + 1, sub, list_sub);
        sub.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        std::vector<int> sub;
        std::vector<std::vector<int>> list_sub;

        recursive(nums, 0, sub, list_sub);

        return list_sub;
    }
    
    
/*  wrong...
    void iterative(const std::vector<int>& nums, const std::size_t idx, std::stack<std::size_t>& stack,
                   std::vector<std::size_t>& markers, std::vector<std::vector<int>>& list_sub)
    {

        stack.push(0);
        while (stack.empty() == false) {
            const auto idx_level = stack.top();
            ++markers[idx_level];
            if (markers[idx_level] > 1) {
                markers[idx_level] = 0;
            }
            stack.pop();

            if (idx_level == nums.size()) {
                std::vector<int> sub;
                for (std::size_t i = 1; i != markers.size(); ++i) {
                    if (markers[i] == 1) {
                        sub.push_back(nums[i - 1]);
                    }
                }

                list_sub.push_back(sub);

                continue;
            }

            markers[idx_level + 1] = 0;
            stack.push(idx_level + 1);

            markers[idx_level + 1] = 1;
            stack.push(idx_level + 1);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        std::stack<std::size_t> stack;
        std::vector<std::size_t> markers(nums.size() + 1, 0);
        std::vector<std::vector<int>> list_sub;

        iterative(nums, 0, stack, markers, list_sub);

        return list_sub;
    }
*/
};