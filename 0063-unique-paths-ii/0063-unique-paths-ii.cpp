///*
// Approach 1: Dynamic Programming - 1d array
constexpr auto one = std::size_t(1);
class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        const auto len_row = obstacleGrid.size();
        const auto len_col = obstacleGrid.front().size();
        std::vector<int> dp(len_col);

        {
            auto col = 0;
            while (col != len_col && obstacleGrid[0][col] == 0) {
                dp[col++] = 1;
            }
            while (col != len_col) {
                dp[col++] = 0;
            }
        }

        for (auto row = std::size_t(1); row != len_row; ++row) {

            //dp[0] = (dp[0] == 0 || obstacleGrid[row][0] == 1) ? 0 : 1;
            dp[0] *= (1 - obstacleGrid[row][0]);

            for (auto col = std::size_t(1); col != len_col; ++col) {
                dp[col] = obstacleGrid[row][col] == 1 ? 0 : dp[col] + dp[col - std::size_t(1)];
            }
        }

        return dp.back();
    }
};
//*/