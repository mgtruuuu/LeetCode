class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        const auto n_row = static_cast<int>(matrix.size());
        const auto n_col = static_cast<int>(matrix.front().size());

        //const auto [min, max] = std::minmax_element(n_row, n_col);
        const auto min = std::min(n_row, n_col);
        const auto half_min = min / 2;
        const auto remainder = min % 2;
        const auto is_wide_matrix = (n_row < n_col);

        auto res = std::vector<int>();
        res.reserve(n_row * n_col);

        for (auto i = 0; i != half_min; ++i) {
            for (auto u = i; u != n_col - 1 - i; ++u) {
                res.push_back(matrix[i][u]);
            }
            for (auto v = i; v != n_row - 1 - i; ++v) {
                res.push_back(matrix[v][n_col - 1 - i]);
            }

            for (auto u = n_col - 1 - i; u != i; --u) {
                res.push_back(matrix[n_row - 1 - i][u]);
            }

            for (auto v = n_row - 1 - i; v != i; --v) {
                res.push_back(matrix[v][i]);
            }
        }

        if (remainder == 1) {
            if (n_row < n_col) {
                for (auto u = half_min; u != n_col - half_min; ++u) {
                    res.push_back(matrix[half_min][u]);
                }
            }
            else {
                for (auto v = half_min; v != n_row - half_min; ++v) {
                    res.push_back(matrix[v][half_min]);
                }
            }
        }

        return res;
    }
};