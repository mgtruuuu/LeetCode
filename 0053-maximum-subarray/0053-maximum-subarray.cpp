// Approach 1: Optimized Brute Force


///*
// Approach 2 - 1 : Dynamic Programming, Kadane's Algorithm
class Solution {
  public:
    int maxSubArray(std::vector<int>& nums)
    {
        // Initialize our variables using the first element.
        auto current_subarray = nums[0];
        auto max_subarray = nums[0];

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
// Approach 2 - 2 : Dynamic Programming, Kadane's Algorithm <------ My solution
class Solution {
  public:
    int maxSubArray(vector<int>& nums)
    {
        const auto len = static_cast<int>(nums.size());

        auto res = INT_MIN;

        auto idx = 0;
        while (idx != len) {

            auto sum_part = 0;

            while (idx != len && sum_part >= 0) {

                sum_part += nums[idx++];

                if (res < sum_part) {
                    res = sum_part;
                }
            };
        }

        return res;
    }
};
*/