///*
// Approach 1: Brute Force Recursion
class Solution {
  public:
    void dp(const int row, const int col, std::vector<std::vector<int>>& matrix)
    {
        if (matrix[row][col] != -1) {
            return;
        }

        if (row == 0 || col == 0 || row == col) {

            matrix[row][col] = 1;
            return;
        }

        dp(row - 1, col - 1, matrix);
        dp(row - 1, col, matrix);
        matrix[row][col] = matrix[row - 1][col - 1] + matrix[row - 1][col];
    }

    vector<int> getRow(int rowIndex)
    {
        auto matrix = std::vector<std::vector<int>>(rowIndex + 1, std::vector<int>(rowIndex + 1, -1));
        vector<int> row;

        for (int i = 0; i <= rowIndex; i++) {
            dp(rowIndex, i, matrix);
        }

        return matrix.back();
    }
};
//*/


/*
// Approach 2: Memory-efficient Dynamic Programming
class Solution {
  public:
    vector<int> getRow(int rowIndex)
    {
        auto row = std::vector<int>(rowIndex + 1, 1);

        for (auto r = 2; r <= rowIndex; ++r) {
            for (auto c = r; c-- != 1;) {
                row[c] += row[c - 1];
            }
        }

        return row;
    }
};
*/