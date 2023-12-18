class Solution {
  public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix)
    {
        const auto num_rows = static_cast<int>(matrix.size());
        const auto num_cols = static_cast<int>(matrix.front().size());

        std::unordered_map<int, int> h;

        for (auto r = 0; r != num_rows; ++r) {
            for (auto c = 0; c != num_cols; ++c) {

                if (h.find(r - c) == h.end()) {
                    h[r - c] = matrix[r][c];
                }
                else if (h[r - c] != matrix[r][c]) {
                    return false;
                }
            }
        }

        return true;
    }
};