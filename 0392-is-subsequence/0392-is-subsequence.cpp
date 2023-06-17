class Solution {
  public:
    bool isSubsequence(string s, string t)
    {
        if (s.empty() == true) {
            return true;
        }
        
        auto idx_sub = std::size_t(0);
        for (auto idx = std::size_t(0); idx != t.size(); ++idx) {
            if (s[idx_sub] == t[idx]) {
                ++idx_sub;

                if (idx_sub == s.size()) {
                    return true;
                }
            }
        }

        return false;
    }
};