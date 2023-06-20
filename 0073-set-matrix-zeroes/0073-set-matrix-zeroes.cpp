class Solution {
  public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        const auto n_row = matrix.size();
        const auto n_col = matrix.front().size();

        std::unordered_set<std::size_t> indices_row;
        std::unordered_set<std::size_t> indices_col;

        for (auto row = std::size_t(0); row != n_row; ++row) {
            for (auto col = std::size_t(0); col != n_col; ++col) {
                if (matrix[row][col] == 0) {
                    indices_row.insert(row);
                    indices_col.insert(col);
                }
            }
        }

        for (auto row = std::size_t(0); row != n_row; ++row) {
            for (auto col = std::size_t(0); col != n_col; ++col) {
                if (indices_row.count(row) == 1 || indices_col.count(col) == 1) {
                    matrix[row][col] = 0;
                }
            }
        }
    }
};