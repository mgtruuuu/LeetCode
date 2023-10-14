/*
// Approach 1: Dynamic Programming
class Solution {
  public:
    int lengthOfLIS(vector<int>& nums)
    {
        const auto len_nums = nums.size();

        auto res = INT_MIN;
        
        std::vector<int> dps(len_nums);

        for (auto idx_right = std::size_t(0); idx_right != len_nums; ++idx_right) {

            dps[idx_right] = 1;

            for (auto idx_left = std::size_t(0); idx_left != idx_right; ++idx_left) {
                
                if (nums[idx_left] < nums[idx_right] && dps[idx_right] < dps[idx_left] + 1) {
                    dps[idx_right] = dps[idx_left] + 1;
                }
            }
            
            if (res < dps[idx_right]) {
                res = dps[idx_right];
            }
        }

        return res;
    }
};
*/



class Solution {
  public:
    int lengthOfLIS(vector<int>& nums)
    {
        std::vector<int> subs{ nums.front() };

        const auto len_nums = static_cast<int>(nums.size());
        for (auto idx = 1; idx != len_nums; ++idx) {

            auto idx_left = int(subs.size()) - 1;

            while (idx_left >= 0 && subs[idx_left] >= nums[idx]) {
                --idx_left;
            }

            if (idx_left == subs.size() - 1) {
                subs.push_back(nums[idx]);
            }
            else {
                subs[idx_left + 1] = nums[idx];
            }
        }

        return subs.size();
    }
};