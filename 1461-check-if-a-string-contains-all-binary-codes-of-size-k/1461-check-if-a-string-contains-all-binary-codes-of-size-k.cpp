class Solution {
  public:
    bool hasAllCodes(string s, int k)
    {
        if (static_cast<int>(s.size()) < k) {
            return false;
        }

        auto need = 1 << k;
        const auto full = need - 1;
        std::vector<bool> got(need, false);

        
        auto window = 0;
        for (auto idx = 0; idx != k - 1; ++idx) {
            window &= full;
            window <<= 1;
            window += static_cast<int>(s[idx] - '0');
        }
        for (auto idx = k - 1; idx != s.size(); ++idx) {
            window <<= 1;
            window &= full;
            window += static_cast<int>(s[idx] - '0');
        
            if (got[window] == true) {
                continue;
            }
            
            got[window] = true;
            
            if (--need == 0) {
                return true;
            }
        }

        return false;
    }
};