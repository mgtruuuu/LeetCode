class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        const uint8_t monotone_increasing = 1 << 0;
        const uint8_t monotone_decreasing = 1 << 1;
        uint8_t monotone = monotone_increasing | monotone_decreasing;
        
        for (auto idx = std::size_t(0); idx != nums.size() - 1; ++idx) {
            
            if (nums[idx + 1] - nums[idx] > 0) {
                monotone &= (monotone_decreasing ^ 0);
            }
            else if (nums[idx + 1] - nums[idx] < 0) {
                monotone &= (monotone_increasing ^ 0);
            }
            else {
                continue;
            }
            
            if (monotone == 0) {
                return false;
            }
        }
        
        return true;
    }
};





// // class Solution
// // {
// // public:
// //     bool isMonotonic(vector<int> &nums)
// //     {

// //         if (nums.size() == 1)
// //         {
// //             return true;
// //         }

// //         auto idx = std::size_t(1);

// //         bool is_diff_positive;
// //         while (idx != nums.size())
// //         {
// //             if (nums[0] != nums[idx])
// //             {

// //                 is_diff_positive = nums[0] < nums[idx] ? true : false;

// //                 break;
// //             }

// //             ++idx;
// //         }

// //         if (idx == nums.size())
// //         {
// //             return true;
// //         }

// //         ++idx;

// //         if (is_diff_positive == true)
// //         {
// //             for (; idx != nums.size(); ++idx)
// //             {
// //                 if (nums[idx] - nums[idx - 1] < 0)
// //                 {
// //                     return false;
// //                 }
// //             }
// //         }
// //         else
// //         {
// //             for (; idx != nums.size(); ++idx)
// //             {
// //                 if (nums[idx] - nums[idx - 1] > 0)
// //                 {
// //                     return false;
// //                 }
// //             }
// //         }

// //         return true;
// //     }
// // };