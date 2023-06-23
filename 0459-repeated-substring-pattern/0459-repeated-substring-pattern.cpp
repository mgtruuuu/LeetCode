class Solution {
  public:
    bool repeatedSubstringPattern(string s)
    {
        const auto len_s = static_cast<int>(s.size());
        const auto value = getLPS(s).back();

        if (value != 0 && len_s % (len_s - value) == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    
    std::vector<int> getLPS(const std::string& arr)
    {
        auto lps = std::vector<int>(arr.size());

        lps[0] = 0;

        for (auto idx = std::size_t(1); idx != arr.size(); ++idx) {
            if (arr[lps[idx - 1]] == arr[idx]) {
                lps[idx] = lps[idx - 1] + 1;

                continue;
            }

            auto count = lps[idx - 1];

            while (count != 0) {
                auto check = true;
                auto idx_rhs = idx;
                for (auto idx_lhs = count; idx_lhs-- != 0;) {
                    if (arr[idx_lhs] != arr[idx_rhs--]) {
                        check = false;

                        break;
                    }
                }

                if (check == true) {
                    break;
                }

                --count;
            }

            lps[idx] = count;
        }

        return lps;
    }
};