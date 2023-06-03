class Solution {
  public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        const auto row_size = triangle.size();
        const auto col_size = row_size;

        for (size_t row = row_size - 1; row-- != 0;) {
            for (size_t col = 0; col != row + 1; ++col) {
                const auto min = triangle[row + 1][col] < triangle[row + 1][col + 1] ? triangle[row + 1][col]
                                                                                     : triangle[row + 1][col + 1];

                triangle[row][col] += min;
            }
        }

        return triangle[0][0];
    }
};