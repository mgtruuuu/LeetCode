class Solution {
  private:
    int getOneDIndex(const int len_col, const int r, const int c)
    {
        return len_col * r + c;
    }

    std::div_t getTwoDIndex(const int len_col, const int idx)
    {
        return std::div(idx, len_col);
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