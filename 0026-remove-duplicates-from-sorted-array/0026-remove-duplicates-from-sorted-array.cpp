class Solution {
  public:
    int removeDuplicates(vector<int>& nums)
    {
        auto idx_lhs = 1;
        std::size_t idx_rhs = 0;
        auto current_num = nums[idx_rhs];

        for (idx_rhs = 1; idx_rhs != nums.size(); ++idx_rhs) {

            if (nums[idx_rhs] == current_num) {
                continue;
            }

            current_num = nums[idx_rhs];
            std::swap(nums[idx_lhs], nums[idx_rhs]);
            ++idx_lhs;
        }

        return idx_lhs;
        
    }
};