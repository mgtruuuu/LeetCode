class Solution {
  public:
    int countNegatives(vector<vector<int>>& grid)
    {
        auto count = 0;
        const auto len_col = static_cast<int>(grid.front().size());

        for (const auto& row : grid) {

            count += static_cast<int>(
                std::distance(std::upper_bound(row.begin(), row.end(), 0, std::greater<int>()), row.end()));
        }

        return count;
    }
};