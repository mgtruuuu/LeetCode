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