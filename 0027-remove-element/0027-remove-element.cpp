class Solution {
  public:
    int removeElement(vector<int>& nums, int val)
    {
        auto p_left = 0;

        auto p_right = static_cast<int>(nums.size()) - 1;

        while (p_left <= p_right) {

            if (nums[p_left] != val) {
                ++p_left;
                
                continue;
            }

            if (nums[p_right] == val) {
                --p_right;
                
                continue;
            }

            std::swap(nums[p_left], nums[p_right]);
        }

        return p_left;
    }
};