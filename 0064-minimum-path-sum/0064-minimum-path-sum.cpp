constexpr auto one = std::size_t(1);

class Solution {
  public:
    int minPathSum(vector<vector<int>>& grid)
    {
        const auto len_row = grid.size();
        const auto len_col = grid.front().size();

        std::vector<std::vector<int>> paths(len_row, std::vector<int>(len_col));

        {
            paths[0][0] = grid.front().front();

            auto sum = 0;
            auto row = std::size_t(0);
            while (row != len_row) {

                sum += grid[row][0];
                paths[row++][0] = sum;
            }

            sum = 0;
            auto col = std::size_t(0);
            while (col != len_col) {

                sum += grid[0][col];
                paths[0][col++] = sum;
            }
        }

        for (auto row = one; row != len_row; ++row) {
            for (auto col = one; col != len_col; ++col) {
                paths[row][col] = std::min(paths[row - one][col], paths[row][col - one]) + grid[row][col];
            }
        }

        return paths[len_row - one][len_col - one];
    }
};