class Solution {
  public:
    bool canJump(vector<int>& nums)
    {
        if (nums.size() == 1) {
            return true;
        }

        if (nums[0] == 0) {
            return false;
        }

        for (auto idx = std::size_t(1); idx != nums.size() - 1; ++idx) {

            nums[idx] = std::max(nums[idx], nums[idx - 1] - 1);

            if (nums[idx] == 0) {
                return false;
            }
        }

        return true;
    }
};