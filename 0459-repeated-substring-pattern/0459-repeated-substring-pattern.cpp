class Solution {
  public:
    bool repeatedSubstringPattern(string s)
    {
        const auto len_s = static_cast<int>(s.size());
        const auto value = getLPSLastElement(s);

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

        auto len = 0; // length of the previous longest prefix suffix

        auto idx = std::size_t(1);
        while (idx != arr.size()) {
            if (arr[len] == arr[idx]) {
                lps[idx++] = ++len;
            }
            else {
                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    lps[idx++] = 0;
                }
            }
        }

        return lps;
    }
    
    int getLPSLastElement(const std::string& arr)
    {
        auto lps = std::vector<int>(arr.size());
        lps[0] = 0;

        auto len = 0; // length of the previous longest prefix suffix

        auto idx = std::size_t(1);
        while (idx != arr.size()) {
            if (arr[len] == arr[idx]) {
                lps[idx++] = ++len;
            }
            else {
                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    lps[idx++] = 0;
                }
            }
        }

        return lps.back();
    }
};