class Solution {
  public:
    int diagonalSum(vector<vector<int>>& mat)
    {
        const auto len_mat = mat.size();
        auto sum = 0;

        for (auto idx_row = std::size_t(0); idx_row != len_mat; ++idx_row) {
            sum += mat[idx_row][idx_row] + mat[idx_row][len_mat - 1 - idx_row];
        }

        if (len_mat & 1) {
            sum -= mat[(len_mat - 1) / 2][(len_mat - 1) / 2];
        }

        return sum;
    }
};