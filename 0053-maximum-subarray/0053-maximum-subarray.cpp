/*
// Approach 1 - 1 : Dynamic Programming, Kadane's Algorithm
class Solution {
  public:
    int maxSubArray(vector<int>& nums)
    {
        // Initialize our variables using the first element.
        auto current_subarray = nums.front();
        auto max_subarray = current_subarray;

        // Start with the 2nd element since we already used the first one.
        for (auto idx = std::size_t(1); idx != static_cast<int>(nums.size()); ++idx) {

            if (current_subarray < 0) {
                current_subarray = nums[idx];
            }
            else {
                current_subarray += nums[idx];
            }

            if (max_subarray < current_subarray) {
                max_subarray = current_subarray;
            }
        }

        return max_subarray;
    }
};
*/


/*
// Approach 1 - 2 : My solution <---- NOT EFFICIENT
class Solution {
  public:
    int maxSubArray(vector<int>& nums)
    {
        const auto len_nums = nums.size();

        auto sum_max = INT_MIN;

        auto idx = std::size_t(0);
        while (idx != len_nums) {

            auto sum_part = 0;

            while (idx != len_nums && sum_part >= 0) {

                sum_part += nums[idx++];

                if (sum_max < sum_part) {
                    sum_max = sum_part;
                }
            };
        }

        return sum_max;
    }
};
*/


///*
// Approach 2: Divide and Conquer (Advanced)
class Solution {
  private:
    int maxSubArrayHelper(const std::vector<int>& nums, const int idx_start, const int idx_end)
    {
        if (idx_start > idx_end) {
            return INT_MIN;
        }
        // if (idx_end - idx_start == 0) {
        //     return nums[idx_start];
        // }
        // else if (idx_end - idx_start == 1) {
        //     return getMax(nums[idx_start], nums[idx_end], nums[idx_start] + nums[idx_end]);
        // }

        const auto idx_middle = (idx_start + idx_end) / 2;

        auto part_sum_max_left = 0;
        auto part_sum_max_right = 0;
        {
            auto part_sum = 0;
            for (auto idx = idx_middle - 1; idx >= idx_start; --idx) {
                
                part_sum += nums[idx];

                if (part_sum_max_left < part_sum) {
                    part_sum_max_left = part_sum;
                }
            }

            part_sum = 0;
            for (auto idx = idx_middle + 1; idx <= idx_end; ++idx) {
                
                part_sum += nums[idx];

                if (part_sum_max_right < part_sum) {
                    part_sum_max_right = part_sum;
                }
            }
        }

        const auto best_combined_sum = part_sum_max_left + nums[idx_middle] + part_sum_max_right;

        return getMax(maxSubArrayHelper(nums, idx_start, idx_middle - 1), best_combined_sum, maxSubArrayHelper(nums, idx_middle + 1, idx_end));
    }

    int getMax(const int a, const int b, const int c)
    {
        return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
    }

  public:
    int maxSubArray(std::vector<int>& nums)
    {
        return maxSubArrayHelper(nums, 0, nums.size() - 1);
    }
};
//*/