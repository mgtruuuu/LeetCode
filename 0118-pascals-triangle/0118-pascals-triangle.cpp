class Solution {
  public:
    vector<vector<int>> generate(int numRows)
    {
        std::vector<std::vector<int>> res;
        res.reserve(numRows);

        res.push_back(std::vector<int>{ 1 });
        for (auto idx = 1; idx != numRows; ++idx) {

            std::vector<int> row;
            row.reserve(idx + 1);

            row.push_back(1);
            for (auto idx_col = 1; idx_col != idx; ++idx_col) {
                row.push_back(res[idx - 1][idx_col - 1] + res[idx - 1][idx_col]);
            }
            row.push_back(1);

            res.push_back(std::move(row));
        }

        return res;
    }
};