class Solution {
  public:
    int minPathSum(vector<vector<int>>& grid)
    {
        const auto row_size = grid.size();
        const auto col_size = grid[0].size();

        for (std::size_t col = 1; col != col_size; ++col) {
            grid[0][col] += grid[0][col - 1];
        }

        for (std::size_t row = 1; row != row_size; ++row) {

            grid[row][0] += grid[row - 1][0];

            for (std::size_t col = 1; col != col_size; ++col) {
                grid[row][col] += std::min(grid[row - 1][col], grid[row][col - 1]);
            }
        }

        return grid[row_size - 1][col_size - 1];
    }
};