class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        auto j = -1;        // pointer for zero element
        for (auto idx = 0; idx != static_cast<int>(nums.size()); ++idx)
        {
            if (nums[idx] != 0)
            {
                ++j;
                std::swap(nums[idx], nums[j]);
            }
        }  
    }
};