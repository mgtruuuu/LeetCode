class Solution {
  public:
    int searchInsert(vector<int>& nums, int target)
    {
        auto idx_left = 0;
        auto idx_right = static_cast<int>(nums.size()) - 1;

        while (idx_left <= idx_right) {

            const auto idx_mid = (idx_left + idx_right) / 2;

            if (nums[idx_mid] < target) {
                idx_left = idx_mid + 1;
            }
            else if (nums[idx_mid] > target) {
                idx_right = idx_mid - 1;
            }
            else {
                return idx_mid;
            }
        }

        return idx_left;
    }
};