class Solution {
public:
    bool isMonotonic(vector<int>& nums) {

        if (nums.size() == 1) {
            return true;
        }
        
        auto idx = std::size_t(1);
        
        bool is_diff_positive;
        while (idx != nums.size()) {
            if (nums[0] != nums[idx]) {
                
                is_diff_positive = nums[0] < nums[idx] ? true : false;
                
                break;
            }
            
            ++idx;
        }
        
        if (idx == nums.size()) {
            return true;
        }
        
        ++idx;
            
        if (is_diff_positive == true) {
            for (; idx != nums.size(); ++idx) {
                if (nums[idx] - nums[idx - 1] < 0) {
                    return false;
                }
            }            
        }
        else {
            for (; idx != nums.size(); ++idx) {
                if (nums[idx] - nums[idx - 1] > 0) {
                    return false;
                }
            }
        }

        return true;
    }
};