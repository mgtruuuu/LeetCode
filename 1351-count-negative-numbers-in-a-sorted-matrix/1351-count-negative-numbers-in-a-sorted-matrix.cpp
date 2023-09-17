class Solution {
  public:
    int countNegatives(vector<vector<int>>& grid)
    {
        const auto len_row = static_cast<int>(grid.size());
        auto len_col = static_cast<int>(grid.front().size());

        auto count = 0;

        auto idx_row = 0;
        while (true) {

            if (idx_row == len_row) {
                break;
            }

            const auto upper_bound_zero =
                std::upper_bound(grid[idx_row].begin(), grid[idx_row].begin() + len_col, 0, std::greater<int>());

            const auto idx_start_neg =
                static_cast<int>(std::distance(upper_bound_zero, grid[idx_row].begin() + len_col));

            count += idx_start_neg * (len_row - idx_row);

            len_col -= idx_start_neg;

            ++idx_row;
        }

        return count;
    }
};