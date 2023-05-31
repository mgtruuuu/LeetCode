class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        auto length_min = static_cast<int>(nums.size() + 1);
        
       
        auto sum = 0;
        auto left = 0;
        
        for (auto right = 0; right != static_cast<int>(nums.size()); ++right) {
            
            sum += nums[right];
            
            if (sum < target) {
                continue;
            }
            

            do {
                sum -= nums[left];
                ++left;
            } while (left <= right && sum >= target);
            
            --left;
            sum += nums[left];
            
            length_min = std::min(length_min, right - left + 1);      
        }
        
        if (length_min == static_cast<int>(nums.size()) + 1) {
            return 0;
        }
        
        return length_min;
    }
};