class Solution {
  public:
    int lengthOfLIS(vector<int>& nums)
    {
        const auto len_nums = nums.size();

        std::vector<int> dps(len_nums, 1);

        for (auto idx_rhs = std::size_t(0); idx_rhs != len_nums; ++idx_rhs) {
            for (auto idx_lhs = std::size_t(0); idx_lhs != idx_rhs; ++idx_lhs) {
                if (nums[idx_lhs] < nums[idx_rhs] && dps[idx_rhs] < dps[idx_lhs] + 1) {
                    dps[idx_rhs] = dps[idx_lhs] + 1;
                }
            }
        }

        return *std::max_element(dps.begin(), dps.end());
    }
};