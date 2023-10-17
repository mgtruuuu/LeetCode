class Solution {
  public:
    int findLengthOfLCIS(vector<int>& nums)
    {
        auto len_nums_minus_one = nums.size();
        --len_nums_minus_one;

        auto max_length = 1;
        auto current_length = 1;

        auto idx = 0;
        while (idx != len_nums_minus_one) {

            auto temp = nums[idx++];
            if (temp < nums[idx]) {

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