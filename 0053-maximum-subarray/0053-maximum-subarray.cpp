class Solution {
  public:
    int maxSubArray(std::vector<int>& nums)
    {
        const auto len = static_cast<int>(nums.size());
        
        auto currentSubarray = nums[0];
        auto maxSubarray = nums[0];

        // Start with the 2nd element since we already used the first one.
        for (auto i = 1; i != len; ++i) {
            
            int num = nums[i];
            
            // If current_subarray is negative, throw it away. Otherwise, keep adding to it.
            currentSubarray = std::max(num, currentSubarray + num);
            maxSubarray = std::max(maxSubarray, currentSubarray);
        }

        return maxSubarray;
    }
};