class Solution {
  public:
    bool validWordSquare(vector<string>& words)
    {
        const auto num_rows = static_cast<int>(words.size());

        if (num_rows != static_cast<int>(words.front().size())) {
            return false;
        }

        for (auto i = 0; i != num_rows - 1; ++i) {

            if (words[i].size() < words[i + 1].size()) {
                return false;
            }
        }

        for (auto r = 0; r != num_rows; ++r) {

            const auto len_word = static_cast<int>(words[r].size());

            for (auto c = 0; c < std::min(len_word, r); ++c) {

                if (static_cast<int>(words[c].size()) <= r || words[r][c] != words[c][r]) {

                    std::cout << r << " " << c << std::endl;

                    return false;
                }
            }

            for (auto c = r + 1; c < len_word; ++c) {

                if (static_cast<int>(words[c].size()) <= r || words[r][c] != words[c][r]) {
                    return false;
                }
            }
        }

        return true;
    }
};