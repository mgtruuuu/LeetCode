class Solution {
  public:
    bool wordPattern(string pattern, string s)
    {
        std::unordered_map<char, std::string> char2str;

        auto count = 0;
        auto idx_head = std::size_t(0);
        for (auto idx_tail = std::size_t(0); idx_tail != s.size() + 1; ++idx_tail) {

            if (idx_tail < s.size() && s[idx_tail] != ' ') {
                continue;
            }

            const auto substr_s = s.substr(idx_head, idx_tail - idx_head);
            if (char2str.find(pattern[count]) == char2str.end()) {

                for (const auto& [k, v] : char2str) {
                    if (v == substr_s) {
                        return false;
                    }
                }

                char2str[pattern[count]] = substr_s;
            }
            else if (char2str[pattern[count]] != substr_s) {
                return false;
            }

            idx_head = idx_tail + 1;
            ++count;
        }

        if (count == static_cast<int>(pattern.size())) {
            return true;
        }
        else {
            return false;
        }
    }
};