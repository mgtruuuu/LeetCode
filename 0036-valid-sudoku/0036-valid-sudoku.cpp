constexpr auto sudoku_size = 9;
constexpr auto sudoku_size_root = 3;

class Solution {
  public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        std::set<int> rows[sudoku_size];
        std::set<int> cols[sudoku_size];
        std::set<int> squares[sudoku_size_root][sudoku_size_root];

        for (std::size_t row = 0; row != sudoku_size; ++row) {
            for (std::size_t col = 0; col != sudoku_size; ++col) {

                if (board[row][col] == '.') {

                    continue;
                }

                if (rows[row].find(board[row][col]) != rows[row].end()) {
                    return false;
                }
                rows[row].insert(board[row][col]);

                if (cols[col].find(board[row][col]) != cols[col].end()) {
                    return false;
                }
                cols[col].insert(board[row][col]);

                if (squares[row / 3][col / 3].find(board[row][col]) != squares[row / 3][col / 3].end()) {
                    return false;
                }
                squares[row / 3][col / 3].insert(board[row][col]);
            }
        }

        
        return true;
    }
};