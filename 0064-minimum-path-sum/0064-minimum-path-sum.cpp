/*
// Approach 2: Dynamic Programming 2D
constexpr auto one = std::size_t(1);

class Solution {
  public:
    int minPathSum(vector<vector<int>>& grid)
    {
        const auto len_row = grid.size();
        const auto len_col = grid.front().size();

        std::vector<std::vector<int>> paths(len_row, std::vector<int>(len_col));

        {
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
*/


/*
// Approach 3: Dynamic Programming 1D
class Solution {
  public:
    int minPathSum(vector<vector<int>>& grid)
    {
        const auto len_row = grid.size();
        const auto len_col = grid.front().size();

        std::vector<int> paths(len_col);

        {
            auto sum = 0;
            auto col = std::size_t(0);
            while (col != len_col) {

                sum += grid[0][col];
                paths[col++] = sum;
            }
        }

        for (auto row = std::size_t(1); row != len_row; ++row) {

            paths[0] += grid[row][0];

            for (auto col = std::size_t(1); col != len_col; ++col) {

                if (paths[col] > paths[col - 1]) {
                    paths[col] = paths[col - 1];
                }
                paths[col] += grid[row][col];
            }
        }

        return paths[len_col - std::size_t(1)];
    }
};
*/


///*
// Approach 4: Dynamic Programming (Without Extra Space)
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
//*/