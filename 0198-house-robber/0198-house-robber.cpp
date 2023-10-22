/*
// Approach 1: Recursion with Memoization
class Solution {
  private:
    int robHelper(const vector<int>& nums, const int idx, std::vector<int>& dp)
    {
        if (idx == 0) {
            return dp[0];
        }
        else if (idx == 1) {
            return dp[1];
        }

        if (dp[idx - 1] < 0) {
            dp[idx - 1] = robHelper(nums, idx - 1, dp);
        }

        // if (dp[idx - 2] < 0) {
        //     dp[idx - 2] = robHelper(nums, idx - 2, dp);
        // }

        return std::max(dp[idx - 2] + nums[idx], dp[idx - 1]);
    }

  public:
    int rob(vector<int>& nums)
    {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        std::vector<int> dp(nums.size(), -1);
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
        
        return robHelper(nums, static_cast<int>(nums.size()) - 1, dp);
    }
};
*/


///*
// Approach 3: Optimized Dynamic Programming
class Solution {
  public:
    int rob(vector<int>& nums)
    {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        std::queue<int> queue_part;

        queue_part.push(nums[0]);
        queue_part.push(nums[0] < nums[1] ? nums[1] : nums[0]);

        for (auto idx = std::size_t(2); idx != nums.size(); ++idx) {

            const auto queue_front = queue_part.front();
            const auto queue_back = queue_part.back();

            queue_part.pop();
            queue_part.push(queue_front + nums[idx] < queue_back ? queue_back : queue_front + nums[idx]);
        }

        return queue_part.back();
    }
};
//*/