class Solution {
  public:
    int diagonalSum(vector<vector<int>>& mat)
    {
        const auto len_mat = mat.size();
        auto sum = 0;

        for (auto idx_row = std::size_t(0); idx_row != len_mat; ++idx_row) {
            for (auto idx_col = std::size_t(0); idx_col != len_mat; ++idx_col) {
                if (idx_row + idx_col + 1 == len_mat || idx_row == idx_col) {
                    sum += mat[idx_row][idx_col];
                }
            }
        }

        return sum;
    }
};