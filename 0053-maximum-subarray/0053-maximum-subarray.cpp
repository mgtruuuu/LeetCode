///*
// Approach 1 : Dynamic Programming, Kadane's Algorithm
class Solution {
  public:
    int maxSubArray(std::vector<int>& nums)
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
//*/


/*
// Approach 2 : My solution <---- NOT EFFICIENT
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