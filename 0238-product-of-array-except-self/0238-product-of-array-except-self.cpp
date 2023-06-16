class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        const auto len_nums = nums.size();
        auto res = std::vector<int>(len_nums);
        res[0] = 1;

        for (auto idx = std::size_t(1); idx != len_nums; ++idx) {
            res[idx] = res[idx - 1] * nums[idx - 1];
        }

        auto temp = 1;
        for (auto idx = len_nums - 1; idx-- != 0;) {
            temp *= nums[idx + 1];
            res[idx] *= temp;
        }

        return res;
    }
};