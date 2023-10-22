constexpr auto one = std::size_t(1);

class Solution {
  public:
    int minPathSum(vector<vector<int>>& grid)
    {
        const auto len_row = grid.size();
        const auto len_col = grid.front().size();

        {
            auto col = one;
            while (col != len_col) {

                grid[0][col] += grid[0][col - one];
                ++col;
            }
        }

        for (auto row = one; row != len_row; ++row) {

            grid[row][0] += grid[row - one][0];

            for (auto col = one; col != len_col; ++col) {
                grid[row][col] += std::min(grid[row - one][col], grid[row][col - one]);
            }
        }

        return grid[len_row - one][len_col - one];
    }
};