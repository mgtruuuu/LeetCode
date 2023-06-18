class Solution {
  public:
    int lengthOfLongestSubstring(string s)
    {
        const auto len_s = s.size();

        auto idx_lhs = 0;
        auto idx_rhs = 0;
        auto count = 0;

        std::unordered_map<char, int> hash;

        while (idx_rhs != s.size()) {

            auto ptr = hash.find(s[idx_rhs]);
            if (ptr != hash.end()) {

                if (count < idx_rhs - idx_lhs) {
                    count = idx_rhs - idx_lhs;
                }

                auto i = idx_lhs;
                while (s[i] != ptr->first) {
                    hash.erase(s[i]);
                    ++i;
                }

                idx_lhs = ++i;
            }

            hash[s[idx_rhs]] = idx_rhs;

            ++idx_rhs;
        }

        return count < idx_rhs - idx_lhs ? idx_rhs - idx_lhs : count;
    }
};