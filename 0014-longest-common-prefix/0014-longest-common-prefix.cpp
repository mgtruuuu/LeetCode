class Solution {
  public:
    string longestCommonPrefix(vector<string>& strs)
    {
        auto res = std::string{};

        for (auto idx_zero = 0; idx_zero != strs.front().size(); ++idx_zero) {
            for (auto idx_strs = std::size_t(1); idx_strs != strs.size(); ++idx_strs) {
                if (strs.front()[idx_zero] != strs[idx_strs][idx_zero]) {
                    return res;
                }
            }

            res.push_back(strs.front()[idx_zero]);
        }

        return res;
    }
};