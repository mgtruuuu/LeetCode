#include <algorithm>

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        auto sum_left = 0;
        auto sum_right = std::accumulate(nums.begin() + 1, nums.end(), 0);
        
        if (sum_left == sum_right) {
            return 0;
        }
        
        for (auto idx = 1; idx < static_cast<int>(nums.size()) - 1; ++idx) {
            
            sum_left += nums[idx - 1];
            sum_right -= nums[idx];
            
            if (sum_left == sum_right) {
                return idx;
            }   
        }
        
        sum_left += nums[nums.size() - 2];

        if (sum_left == 0) {
            return static_cast<int>(nums.size()) - 1 ;
        }
        
        return -1;
    }
};