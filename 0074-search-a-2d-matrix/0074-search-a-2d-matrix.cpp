class Solution {
  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        const auto len_row = static_cast<int>(matrix.size());
        const auto len_col = static_cast<int>(matrix.front().size());

        auto idx_row_left = 0;
        auto idx_row_right = len_row - 1;
        auto idx_row = 0;
        while (idx_row_left <= idx_row_right) {

            const auto idx_row_middle = (idx_row_left + idx_row_right) / 2;

            if (matrix[idx_row_middle][0] < target) {
                idx_row_left = idx_row_middle + 1;
            }
            else if (matrix[idx_row_middle][0] > target) {
                idx_row_right = idx_row_middle - 1;
            }
            else {
                return true;
            }
        }

        if (idx_row_left > idx_row_right) {
            idx_row = idx_row_right;
        }

        if (idx_row < 0) {
            return false;
        }
        
        auto idx_col_left = 0;
        auto idx_col_right = len_col - 1;
        while (idx_col_left <= idx_col_right) {

            const auto idx_row_middle = (idx_col_left + idx_col_right) / 2;

            if (matrix[idx_row][idx_row_middle] < target) {
                idx_col_left = idx_row_middle + 1;
            }
            else if (matrix[idx_row][idx_row_middle] > target) {
                idx_col_right = idx_row_middle - 1;
            }
            else {
                return true;
            }
        }

        return false;
    }
};