class Solution {
  public:
    int jump(vector<int>& nums)
    {
        auto len_nums = nums.size();

        auto count = 0;
        auto idx_step_begin = 0;
        auto idx_step_end = 1;

        while (idx_step_end != len_nums) {

            ++count;

            auto temp = 0;
            for (auto p = idx_step_begin; p != idx_step_end; ++p) {

                if (temp < p + nums[p]) {
                    temp = p + nums[p];
                }

                if (temp >= len_nums - 1) {
                    return count;
                }
            }

            idx_step_begin = idx_step_end;
            idx_step_end = ++temp;
        }

        return count;
    }
};


// // class Solution {
// //   public:
// //     int jump(vector<int>& nums)
// //     {
// //         auto len_nums = nums.size();

// //         std::vector<int> counts(len_nums, 10000);
// //         counts[0] = 0;

// //         for (auto idx = std::size_t(0); idx != len_nums - 1; ++idx) {

// //             const auto inner_end = (idx + 1 + nums[idx] < len_nums) ? idx + 1 + nums[idx] : len_nums;

// //             for (auto idx_inner = idx + 1; idx_inner != inner_end; ++idx_inner) {
// //                 if (counts[idx] + 1 < counts[idx_inner]) {
// //                     counts[idx_inner] = counts[idx] + 1;
// //                 }
// //             }
// //         }

// //         return counts[len_nums - 1];
// //     }
// // };