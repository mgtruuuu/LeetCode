class Solution {
  public:
    int findLengthOfLCIS(vector<int>& nums)
    {
        auto max_length = 1;
        auto current_length = 1;
        for (auto idx = std::size_t(1); idx != nums.size(); ++idx) {

            if (nums[idx - 1] < nums[idx]) {

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