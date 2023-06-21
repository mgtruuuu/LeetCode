class Solution {
  public:
    int findLength(vector<int>& nums1, vector<int>& nums2)
    {
        const auto n_row = nums1.size();
        const auto n_col = nums2.size();

        auto getIndex = [n_col](const std::size_t row, const std::size_t col) { return n_col * row + col; };

        std::vector<int> longest_common_prefixes(n_row * n_col, 0);

        auto max_val = 0;
        for (auto row = n_row; row-- != 0;) {
            for (auto col = n_col; col-- != 0;) {

                if (nums1[row] != nums2[col]) {
                    // longest_common_prefixes[getIndex(row, col)] = 0;

                    continue;
                }

                if (row + 1 != n_row && col + 1 != n_col) {
                    longest_common_prefixes[getIndex(row, col)] =
                        longest_common_prefixes[getIndex(row + 1, col + 1)] + 1;

                    if (max_val < longest_common_prefixes[getIndex(row, col)]) {
                        max_val = longest_common_prefixes[getIndex(row, col)];
                    }
                }
                else {
                    longest_common_prefixes[getIndex(row, col)] = 1;

                    if (max_val == 0) {
                        max_val = 1;
                    }
                }
            }
        }

        return max_val;
    }
};