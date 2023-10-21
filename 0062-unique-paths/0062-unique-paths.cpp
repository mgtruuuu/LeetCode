class Solution {
  public:
    int uniquePaths(int m, int n)
    {
        std::vector<std::vector<int>> paths(m, std::vector<int>(n));

        if (m == 1 || n == 1) {
            return 1;
        }

        {
            for (auto row = 0; row != m; ++row) {
                paths[row][0] = 1;
            }

            for (auto col = 0; col != n; ++col) {
                paths[0][col] = 1;
            }
        }

        for (auto row = 1; row != m; ++row) {
            for (auto col = 1; col != n; ++col) {
                paths[row][col] = paths[row - 1][col] + paths[row][col - 1];
            }
        }

        return paths[m - 1][n - 1];
    }
};