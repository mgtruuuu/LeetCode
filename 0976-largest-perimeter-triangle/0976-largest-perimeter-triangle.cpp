class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        
        std::sort(nums.begin(), nums.end());
        
        for (auto idx = nums.size(); idx-- != 2; ) {
        
            if (nums[idx] < nums[idx - 1] + nums[idx - 2]) {
                return nums[idx] + nums[idx - 1] + nums[idx - 2];
            }
        }
        
        return 0;
    }
};