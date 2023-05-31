class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
//        auto j = nums.size();
//        for (auto idx = nums.size(); idx-- != 0;)
//        {
//            if (nums[idx] != 0)
//            {
//                --j;
//                std::swap(nums[idx], nums[j]);
//            }
//        }
        
        auto j = -1;
        for (auto idx = 0; idx != nums.size(); ++idx)
        {
            if (nums[idx] != 0)
            {
                ++j;
                std::swap(nums[idx], nums[j]);
            }
        }  
    }
};