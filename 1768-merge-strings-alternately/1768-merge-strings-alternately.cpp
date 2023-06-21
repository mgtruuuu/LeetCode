class Solution {
  public:
    string mergeAlternately(string word1, string word2)
    {
        std::string res;
        const auto min = word1.size() < word2.size() ? word1.size() : word2.size();
        const auto len = word1.size() + word2.size();
        res.reserve(len);

        auto idx_word1 = word1.begin();
        auto idx_word2 = word2.begin();
        for (auto idx = std::size_t(0); idx != min; ++idx) {
            res.push_back(*idx_word1);
            res.push_back(*idx_word2);

            ++idx_word1;
            ++idx_word2;
        }

        if (idx_word1 != word1.end()) {
            for (auto idx = 2 * min; idx != len; ++idx) {
                res.push_back(*idx_word1);

                ++idx_word1;
            }
        }

        if (idx_word2 != word2.end()) {
            for (auto idx = 2 * min; idx != len; ++idx) {
                res.push_back(*idx_word2);

                ++idx_word2;
            }
        }

        return res;
    }
};