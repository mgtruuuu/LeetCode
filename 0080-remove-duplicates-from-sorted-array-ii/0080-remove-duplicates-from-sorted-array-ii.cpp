class Solution {
  public:
    int removeDuplicates(vector<int>& nums)
    {
        const auto len_nums = nums.size();

        if (len_nums <= 2) {
            return len_nums;
        }

        auto idx_lhs = std::size_t(2);
        for (auto idx_rhs = idx_lhs; idx_rhs != len_nums; ++idx_rhs) {
            if (nums[idx_lhs - 2] == nums[idx_rhs]) {
                continue;
            }

            nums[idx_lhs] = nums[idx_rhs];

            ++idx_lhs;
        }

        return idx_lhs;
    }
};