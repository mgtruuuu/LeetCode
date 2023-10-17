class Solution {
  public:
    int findLengthOfLCIS(vector<int>& nums)
    {
        const auto len_nums = static_cast<int>(nums.size());

        auto max_length = 1;
        auto current_length = 1;
        for (auto idx = 0; idx != len_nums - 1; ++idx) {

            if (nums[idx] < nums[idx + 1]) {

                ++current_length;

                continue;
            }
            else if (max_length < current_length) {
                max_length = current_length;
            }

            current_length = 1;
        }

        if (max_length < current_length) {
            max_length = current_length;
        }
        return max_length;
    }
};
