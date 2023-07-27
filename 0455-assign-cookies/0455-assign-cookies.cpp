class Solution {
  public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        auto idx_g = 0;
        auto idx_s = -1;

        for (; idx_g != static_cast<int>(g.size()); ++idx_g) {

            ++idx_s;

            if (idx_s == static_cast<int>(s.size())) {
                return idx_g;
            }

            while (s[idx_s] < g[idx_g]) {

                ++idx_s;

                if (idx_s == static_cast<int>(s.size())) {
                    return idx_g;
                }
            }

            
        }

        return idx_g;
    }
};