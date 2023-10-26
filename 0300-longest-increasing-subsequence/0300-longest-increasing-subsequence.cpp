class Solution {
  public:
    int lengthOfLIS(vector<int>& nums)
    {
        auto dp = std::vector<int>(nums.size(), 1);

        for (auto idx = std::size_t(1); idx != nums.size(); ++idx) {

            for (auto idx_left = std::size_t(0); idx_left != idx; ++idx_left) {

                if (nums[idx_left] < nums[idx] && dp[idx] < dp[idx_left] + 1) {
                    dp[idx] = dp[idx_left] + 1;
                }
            }
        }
        
        return *std::max_element(dp.begin(), dp.end());
    }
};