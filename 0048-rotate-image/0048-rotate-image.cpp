class Solution {
  public:
    void rotate(vector<vector<int>>& matrix)
    {
        const auto n_mat = matrix.size();

        auto temp = 0;
        for (auto i = 0; i != (matrix.size() >> 1); ++i) {
            for (auto k = i; k != n_mat - 1 - i; ++k) {
                temp = matrix[i][k];
                matrix[i][k] = matrix[n_mat - 1 - k][i];
                matrix[n_mat - 1 - k][i] = matrix[n_mat - 1 - i][n_mat - 1 - k];
                matrix[n_mat - 1 - i][n_mat - 1 - k] = matrix[k][n_mat - 1 - i];
                matrix[k][n_mat - 1 - i] = temp;
            }
        }
    }
};