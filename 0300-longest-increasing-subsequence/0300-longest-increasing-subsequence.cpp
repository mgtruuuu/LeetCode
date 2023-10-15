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

        const auto len_nums = nums.size();
        for (auto idx = std::size_t(1); idx != len_nums; ++idx) {

            auto idx_left = subs.size();
            --idx_left;
            
            while (subs[idx_left] >= nums[idx] && idx_left-- != 0);
            
            if (++idx_left == subs.size()) {
                subs.push_back(nums[idx]);
            }
            else {
                subs[idx_left] = nums[idx];
            }
        }

        return subs.size();
    }
};