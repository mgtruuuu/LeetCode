class Solution {
  public:
    int maxSubArray(vector<int>& nums)
    {
        auto sum = nums.front();
        auto max_sum = sum;

        if (sum < 0) {
            sum = 0;
        }

        for (auto idx = std::size_t(1); idx != nums.size(); ++idx) {
        
            sum += nums[idx];

            if (sum > max_sum) {
                max_sum = sum;
            }

            if (sum < 0) {
                sum = 0;
            }
        }

        return max_sum;
    }
};