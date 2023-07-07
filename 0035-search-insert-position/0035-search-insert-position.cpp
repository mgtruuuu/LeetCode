class Solution {
  public:
    int searchInsert(vector<int>& nums, int target)
    {
        auto idx_lhs = 0;
        auto idx_rhs = static_cast<int>(nums.size()) - 1;

        while (idx_lhs <= idx_rhs) {

            const auto idx_mid = (idx_lhs + idx_rhs) / 2;

            if (nums[idx_mid] < target) {
                idx_lhs = idx_mid + 1;
            }
            else if (nums[idx_mid] > target) {
                idx_rhs = idx_mid - 1;
            }
            else {
                return idx_mid;
            }
        }

        return idx_lhs;
    }
};