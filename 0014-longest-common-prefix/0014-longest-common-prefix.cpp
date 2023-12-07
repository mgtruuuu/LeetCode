///*
// Approach 1: Vertical scanning
class Solution {
  public:
    string longestCommonPrefix(vector<string>& strs)
    {
        auto res = std::string{};

        const auto& str_front = strs.front();

        for (auto idx_front = std::size_t(0); idx_front != str_front.size(); ++idx_front) {

            for (auto idx_strs = std::size_t(1); idx_strs != strs.size(); ++idx_strs) {

                if (idx_front == strs[idx_strs].size() || str_front[idx_front] != strs[idx_strs][idx_front]) {
                    return res;
                }
            }

            res.push_back(str_front[idx_front]);
        }

        return res;
    }
};
//*/