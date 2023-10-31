/*
// Approach 1: Top Down Dynamic Programming - Memoization
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
*/


/*
// Approach 2: Bottom Up Dynamic Programming
class Solution {
  public:
    bool canPartition(vector<int>& nums)
    {
        auto half_sum = std::accumulate(nums.begin(), nums.end(), 0);

        if (half_sum & 1) {
            return false;
        }
        half_sum /= 2;

        auto dp = std::vector<std::vector<bool>>(nums.size() + 1, std::vector<bool>(half_sum + 1));
        {
            for (auto row = 0; row != nums.size() + 1; ++row) {
                dp[row][0] = true;
            }

            for (auto col = 1; col != half_sum + 1; ++col) {
                dp[0][col] = false;
            }
        }

        for (auto row = 1; row != nums.size() + 1; ++row) {
            for (auto col = 1; col != half_sum + 1; ++col) {

                if (dp[row - 1][col] == true) {

                    dp[row][col] = true;

                    continue;
                }

                if (col >= nums[row - 1] && dp[row - 1][col - nums[row - 1]] == true) {

                    dp[row][col] = true;

                    continue;
                }

                dp[row][col] = false;
            }
        }

        return dp.back().back();
    }
};
*/


class Solution {
  public:
    bool canPartition(vector<int>& nums)
    {
        auto half_sum = std::accumulate(nums.begin(), nums.end(), 0);

        if (half_sum & 1) {
            return false;
        }
        half_sum /= 2;

        auto dp = std::vector<bool>(half_sum + 1, false);
        dp[0] = true;

        for (auto row = 1; row != nums.size() + 1; ++row) {
            for (auto col = half_sum + 1; col-- != 0;) {

                if (dp[col] == true) {
                    continue;
                }

                if (col >= nums[row - 1] && dp[col - nums[row - 1]] == true) {
                    dp[col] = true;
                }
            }
        }

        return dp.back();
    }
};