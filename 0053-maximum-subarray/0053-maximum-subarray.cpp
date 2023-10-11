class Solution {
  public:
    int maxSubArray(vector<int>& nums)
    {
        const auto len = static_cast<int>(nums.size());

        auto res = INT_MIN;
        
        
        auto idx = 0;
        while (idx != len) {
            
            auto sum_part = 0;
            
            while (idx != len && sum_part >= 0) {
                
                sum_part += nums[idx++];
                
                if (res < sum_part) {
                    res = sum_part;
                }
            };
        }

        return res;
    }
};