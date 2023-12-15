class NumMatrix {
  public:
    NumMatrix(vector<vector<int>>& matrix)
    {
        const auto len_row = matrix.size();
        const auto len_col = matrix.front().size();

        m_sums = std::vector<std::vector<int>>(len_row + 1, std::vector<int>(len_col + 1));

        {
            m_sums[0][0] = 0;

            for (auto c = std::size_t(1); c != len_col + 1; ++c) {
                m_sums[0][c] = 0;
            }

            for (auto r = std::size_t(1); r != len_row + 1; ++r) {
                m_sums[r][0] = 0;
            }
        }

        for (auto r = std::size_t(0); r != len_row; ++r) {
            for (auto c = std::size_t(0); c != len_col; ++c) {
                m_sums[r + 1][c + 1] = m_sums[r][c + 1] + m_sums[r + 1][c] + matrix[r][c] - m_sums[r][c];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return m_sums[row2 + 1][col2 + 1] + m_sums[row1][col1] - m_sums[row2 + 1][col1] - m_sums[row1][col2 + 1];
    }

  private:
    std::vector<std::vector<int>> m_sums;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */