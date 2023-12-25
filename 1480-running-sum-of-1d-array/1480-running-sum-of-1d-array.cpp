class Solution {
public:
    vector<int> runningSum(vector<int> &nums) {
        
        for (auto i = std::size_t(1); i != nums.size(); ++i) {
            nums[i] += nums[i - 1];
        }
        
        return nums;
    }
};