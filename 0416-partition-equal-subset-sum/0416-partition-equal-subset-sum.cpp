class Solution {
  private:
    bool canPartitionHelper(const std::vector<int>& nums, const int row, const int col,
                            std::vector<std::vector<int>>& dp)
    {
        if (dp[row][col] != -1) {
            return dp[row][col] == 1;
        }

        if (col == 0) {

            dp[row][col] = 1;
            return true;
        }

        if (row == 0) {

            dp[row][col] = 0;
            return false;
        }
        
        if (canPartitionHelper(nums, row - 1, col, dp) == true) {

            dp[row][col] = 1;
            return true;
        }

        if (col >= nums[row - 1] && canPartitionHelper(nums, row - 1, col - nums[row - 1], dp) == true) {

            dp[row][col] = 1;
            return true;
        }

        dp[row][col] = 0;
        return false;
    }

  public:
    bool canPartition(vector<int>& nums)
    {
        auto half_sum = std::accumulate(nums.begin(), nums.end(), 0);

        if (half_sum & 1) {
            return false;
        }
        half_sum /= 2;

        auto dp = std::vector<std::vector<int>>(nums.size() + 1, std::vector<int>(half_sum + 1, -1));
        return canPartitionHelper(nums, nums.size(), half_sum, dp) == true;
    }
};