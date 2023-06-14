class Solution {
  public:
    int removeDuplicates(vector<int>& nums)
    {
        const auto len_nums = nums.size();

        if (len_nums <= 2) {
            return len_nums;
        }

        auto idx_lhs = std::size_t(2);
        for (auto idx_rhs = idx_lhs; idx_rhs != len_nums; ++idx_rhs) {
            if (nums[idx_lhs - 2] == nums[idx_rhs]) {
                continue;
            }

            nums[idx_lhs] = nums[idx_rhs];

            ++idx_lhs;
        }

        return idx_lhs;
    }
};



// // class Solution {
// //   public:
// //     int removeDuplicates(vector<int>& nums)
// //     {
// //         const auto len_nums = nums.size();

// //         if (len_nums <= 2) {
// //             return len_nums;
// //         }

// //         auto idx_lhs = std::size_t(2);
// //         while (idx_lhs != len_nums) {
// //             if (nums[idx_lhs - 2] == nums[idx_lhs]) {
// //                 break;
// //             }

// //             ++idx_lhs;
// //         }

// //         for (auto idx_rhs = idx_lhs + 1; idx_rhs < len_nums; ++idx_rhs) {

// //             if (nums[idx_lhs - 1] == nums[idx_rhs]) {
// //                 continue;
// //             }

// //             do {
// //                 std::swap(nums[idx_lhs], nums[idx_rhs]);
// //                 ++idx_lhs;
// //                 ++idx_rhs;

// //                 if (idx_rhs == len_nums) {
// //                     return idx_lhs;
// //                 }
// //             } while (nums[idx_lhs - 2] != nums[idx_lhs - 1]);

// //             --idx_rhs;
// //         }

// //         return idx_lhs;
// //     }
// // };