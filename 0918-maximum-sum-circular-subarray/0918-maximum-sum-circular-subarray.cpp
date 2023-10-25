class Solution {
  public:
    int maxSubarraySumCircular(vector<int>& nums)
    {
        auto curr_max_subarray = nums.front();
        auto curr_min_subarray = nums.front();
        auto sum_max_subarray = curr_max_subarray;
        auto sum_min_subarray = curr_min_subarray;
        auto sum_total = nums[0];
        bool all_positive = true;
        bool all_negative = true;
        
        for (auto idx = std::size_t(1); idx != static_cast<int>(nums.size()); ++idx) {

            if (curr_max_subarray < 0) {
                curr_max_subarray = nums[idx];
            }
            else {
                curr_max_subarray += nums[idx];
            }

            if (sum_max_subarray < curr_max_subarray) {
                sum_max_subarray = curr_max_subarray;
            }

            
            if (curr_min_subarray > 0) {
                curr_min_subarray = nums[idx];
            }
            else {
                curr_min_subarray += nums[idx];
            }

            if (sum_min_subarray > curr_min_subarray) {
                sum_min_subarray = curr_min_subarray;
            }

            sum_total += nums[idx];
            
            if (all_positive == true && nums[idx] < 0) {
                all_positive = false;
            }
            if (all_negative == true && nums[idx] > 0) {
                all_negative = false;
            }
        }

        if (all_positive == true || all_negative == true) {
            return sum_max_subarray;
        }
        else {
            return std::max(sum_total - sum_min_subarray, sum_max_subarray);
        }
    }
};