class Solution {
  public:
    int jump(vector<int>& nums)
    {
        auto len_nums = nums.size();

        std::vector<int> counts(len_nums, 10000);
        counts[0] = 0;

        for (auto idx = std::size_t(0); idx != len_nums - 1; ++idx) {

            const auto inner_end = (idx + 1 + nums[idx] < len_nums) ? idx + 1 + nums[idx] : len_nums;

            for (auto idx_inner = idx + 1; idx_inner != inner_end; ++idx_inner) {
                if (counts[idx] + 1 < counts[idx_inner]) {
                    counts[idx_inner] = counts[idx] + 1;
                }
            }
        }

        return counts[len_nums - 1];
    }
};