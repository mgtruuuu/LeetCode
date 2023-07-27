class Solution {
  public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        auto idx_g = std::size_t(0);
        auto idx_s = std::size_t(0);
        if (idx_s == s.size()) {
            return static_cast<int>(idx_g);
        }

        for (; idx_g != g.size(); ++idx_g) {

            if (idx_s == s.size()) {
                return static_cast<int>(idx_g);
            }
            
            while (s[idx_s] < g[idx_g]) {

                ++idx_s;

                if (idx_s == s.size()) {
                    return static_cast<int>(idx_g);
                }
            }
            
            ++idx_s;
        }

        return static_cast<int>(idx_g);
    }
};