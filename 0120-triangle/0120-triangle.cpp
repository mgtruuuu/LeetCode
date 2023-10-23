/*
// Approach 1: Dynamic Programming (Bottom-up: In-place)
constexpr auto one = std::size_t(1);
class Solution {
  public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        std::vector<std::vector<int>> dp(triangle.size());
        for (auto i = std::size_t(0); i != dp.size(); ++i) {
            dp[i].resize(i + 1);
        }

        dp.front().front() = triangle.front().front();
        for (auto row = one; row != dp.size(); ++row) {

            dp[row][0] = triangle[row][0] + dp[row - one][0];
            for (auto col = one; col != row; ++col) {
                dp[row][col] = triangle[row][col] + std::min(dp[row - one][col - one], dp[row - one][col]);
            }
            dp[row][row] = triangle[row][row] + dp[row - one][row - one];
        }

        return *std::min_element(dp.back().begin(), dp.back().end());
    }
};
*/


/*
// Approach 2: Dynamic Programming (Bottom-up: Flip Triangle Upside Down)
constexpr auto one = std::size_t(1);
class Solution {
  public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        for (auto row = triangle.size() - one; row-- != 0;) {
            for (auto col = row + one; col-- != 0;) {
                triangle[row][col] += std::min(triangle[row + 1][col], triangle[row + 1][col + 1]);
            }
        }

        return triangle[0][0];
    }
};
*/


///*
// Approach 3: Dynamic Programming (Bottom-up: Flip Triangle Upside Down)
// using only O(n) extra space, where n is the total number of rows in the triangle?
constexpr auto one = std::size_t(1);
class Solution {
  public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        auto dp = triangle.back();

        for (auto row = triangle.size() - one; row-- != 0;) {
            for (auto col = std::size_t(0); col != row + one; ++col) {
                dp[col] = std::min(dp[col], dp[col + 1]) + triangle[row][col];
            }
        }

        return dp[0];
    }
};
//*/