class Solution {
  public:
    int countNegatives(vector<vector<int>>& grid)
    {
        const auto len_row = static_cast<int>(grid.size());
        auto len_col = static_cast<int>(grid.front().size());

        auto count = 0;

        for (auto idx_row = 0; idx_row != len_row; ++idx_row) {

            const auto upper_bound_zero =
                std::upper_bound(grid[idx_row].begin(), grid[idx_row].begin() + len_col, 0, std::greater<int>());

            const auto num_negatives =
                static_cast<int>(std::distance(upper_bound_zero, grid[idx_row].begin() + len_col));

            count += num_negatives * (len_row - idx_row);

            len_col -= num_negatives;
        }

        return count;
    }
};