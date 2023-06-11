class Solution {
  public:
    int removeDuplicates(vector<int>& nums)
    {
        const auto len_nums = static_cast<int>(nums.size());

        auto current_num = nums[0];
        auto p_left = 0;
        auto p_right = 0;

        do {
            if (p_right == len_nums - 1) {
                return 1;
            }

            ++p_right;
        } while (nums[p_right] == current_num);

        p_left = 1;
        std::swap(nums[p_left], nums[p_right]);
        current_num = nums[p_left];
        ++p_left;
        ++p_right;

        while (p_right != len_nums) {
            while (nums[p_right] == current_num) {
                ++p_right;

                if (p_right == static_cast<int>(nums.size())) {
                    return p_left;
                }
            }

            std::swap(nums[p_left], nums[p_right]);
            current_num = nums[p_left];
            ++p_left;
            ++p_right;
        }

        return p_left;
    }
};