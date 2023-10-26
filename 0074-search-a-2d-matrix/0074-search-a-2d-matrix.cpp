/*
// Approach 1 - 1: Binary Search
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
*/


///*
// Approach 1 - 2: Binary Search
class Solution {
  private:
    int getOneDIndex(const int len_col, const int r, const int c)
    {
        return len_col * r + c;
    }

    std::div_t getTwoDIndex(const int len_col, const int idx_one_d)
    {
        return std::div(idx_one_d, len_col);
    }

  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        const auto len_row = static_cast<int>(matrix.size());
        const auto len_col = static_cast<int>(matrix.front().size());

        auto idx_one_d_front = 0;
        auto idx_one_d_back = getOneDIndex(len_col, len_row - 1, len_col - 1);
        int idx_one_d_middle;
        div_t div;
        while (idx_one_d_front <= idx_one_d_back) {

            idx_one_d_middle = (idx_one_d_front + idx_one_d_back) / 2;

            div = getTwoDIndex(len_col, idx_one_d_middle);
            if (target < matrix[div.quot][div.rem]) {
                idx_one_d_back = idx_one_d_middle - 1;
            }
            else if (target > matrix[div.quot][div.rem]) {
                idx_one_d_front = idx_one_d_middle + 1;
            }
            else {
                return true;
            }
        }

        return false;
    }
};
//*/