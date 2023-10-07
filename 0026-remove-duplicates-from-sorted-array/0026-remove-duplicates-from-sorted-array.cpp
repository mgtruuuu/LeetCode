class Solution {
  public:
    int removeDuplicates(vector<int>& nums)
    {
        auto idx_lhs = std::size_t(0);
        for (auto idx_rhs = std::size_t(1); idx_rhs != nums.size(); ++idx_rhs) {

            if (nums[idx_lhs] >= nums[idx_rhs]) {
                continue;
            }

            std::swap(nums[++idx_lhs], nums[idx_rhs]);
        }

        return idx_lhs + 1;
    }
};