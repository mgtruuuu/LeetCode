class Solution {
  public:
    void moveZeroes(vector<int>& nums)
    {
        auto idx_lhs = std::size_t(0);
        while (nums[idx_lhs] != 0) {
            if (idx_lhs == nums.size() - 1) {
                return;
            }

            ++idx_lhs;
        }

        for (auto idx_rhs = idx_lhs + 1; idx_rhs != nums.size(); ++idx_rhs) {

            if (nums[idx_rhs] == 0) {
                continue;
            }

            std::swap(nums[idx_lhs], nums[idx_rhs]);

            ++idx_lhs;
        }
    }
};