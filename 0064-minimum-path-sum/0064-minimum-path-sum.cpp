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