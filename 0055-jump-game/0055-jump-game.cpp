class Solution {
  public:
    bool canJump(vector<int>& nums)
    {
        if (nums.size() == 1) {
            return true;
        }

        auto temp = nums[0];

        if (temp == 0) {
            return false;
        }

        for (auto idx = std::size_t(1); idx != nums.size() - 1; ++idx) {

            temp = std::max(nums[idx], temp - 1);

            if (temp == 0) {
                return false;
            }
        }

        return true;
    }
};