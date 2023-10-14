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
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> sub;
        sub.push_back(nums[0]);
        
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            if (num > sub.back()) {
                sub.push_back(num);
            } else {
                // Find the first element in sub that is greater than or equal to num
                auto it = std::lower_bound(sub.begin(), sub.end(), num);
                *it = num;
            }
        }
        
        return sub.size();
    }
};
