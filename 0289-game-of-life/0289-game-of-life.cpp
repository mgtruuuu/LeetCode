class Solution {
  public:
    void gameOfLife(vector<vector<int>>& board)
    {
        auto updateCell = [&board](const std::size_t row, const std::size_t col) {
            const auto box_min_row = (row == 0 ? row : row - 1);
            const auto box_max_row = (row == board.size() - 1 ? row : row + 1);
            const auto box_min_col = (col == 0 ? col : col - 1);
            const auto box_max_col = (col == board.front().size() - 1 ? col : col + 1);

            auto sum = 0;
            for (auto idx_row = box_min_row; idx_row <= box_max_row; ++idx_row) {
                for (auto idx_col = box_min_col; idx_col <= box_max_col; ++idx_col) {
                    if (idx_row == row && idx_col == col) {
                        continue;
                    }

                    sum += (board[idx_row][idx_col] & 1);
                }
            }

            if ((board[row][col] == 0 && sum == 3) || (board[row][col] == 1 && (sum == 2 || sum == 3))) {
                board[row][col] += (1 << 1);
            }
        };

        for (auto idx_row = std::size_t(0); idx_row != board.size(); ++idx_row) {
            for (auto idx_col = std::size_t(0); idx_col != board.front().size(); ++idx_col) {
                updateCell(idx_row, idx_col);
            }
        }

        for (auto& row : board) {
            for (auto& ele : row) {
                ele >>= 1;
            }
        }
    }
};