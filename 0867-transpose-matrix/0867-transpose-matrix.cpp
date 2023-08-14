class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix)
    {
        const auto len_row = matrix.size();
        const auto len_col = matrix.front().size();
        
        std::vector<std::vector<int>> res(len_col);
        
        std::vector<int> row(len_row);
        for (auto& col : res) {
            col = row;
        }
        
        for (auto i = std::size_t(0); i != len_col; ++i)
        {                        
            for (auto j = std::size_t(0); j != len_row; ++j)
            {
                res[i][j] = matrix[j][i];
            }
        }
            
        return res;
    }
};