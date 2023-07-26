class Solution {
  public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        
        auto idx_g = 0;
        auto idx_s = 0;
        while (idx_g < static_cast<int>(g.size()) && idx_s < static_cast<int>(s.size())) {
            
            if (g[idx_g] <= s[idx_s]) {
                ++idx_g;
            }            
            
            ++idx_s;
        }
        
        return static_cast<int>(idx_g);
    }
};