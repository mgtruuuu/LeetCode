class Solution {
  private:
    int calculate(const std::vector<std::string>& strs, const int row, const int m, const int n,
                  std::vector<std::vector<std::vector<int>>>& dp)
    {
        if (dp[row][m][n] != -1) {
            return dp[row][m][n];
        }

        if (row == 0) {
            return dp[row][m][n] = 0;
        }

        const auto not_taken = calculate(strs, row - 1, m, n, dp);

        auto num_zeros = 0;
        auto num_ones = 0;
        auto taken = -1;
        getInfo(strs[row - 1], num_zeros, num_ones);
        if (num_zeros <= m && num_ones <= n) {
            taken = calculate(strs, row - 1, m - num_zeros, n - num_ones, dp);
        }

        return dp[row][m][n] = std::max(not_taken, taken + 1);
    }

    void getInfo(const std::string& str, int& num_zeros, int& num_ones)
    {
        num_zeros = num_ones = 0;
        for (const auto ch : str) {
            if (ch == '0') {
                ++num_zeros;
            }
            else {
                ++num_ones;
            }
        }
    }

  public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        auto dp = std::vector<std::vector<std::vector<int>>>(
            strs.size() + 1, std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, -1)));

        return calculate(strs, strs.size(), m, n, dp);
    }
};