class Solution {
  public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        std::sort(s.begin(), s.end());
        std::sort(g.begin(), g.end());

        auto res = 0;

        auto idx_g = 0;
        for (auto idx_s = 0; idx_s < static_cast<int>(s.size()); ++idx_s) {
            if (idx_g != g.size() && g[idx_g] <= s[idx_s]) {
                ++idx_g;
                ++res;
            }
        }

        return res;
    }
};


/*
class Solution {
  public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        auto idx_g = 0;
        auto idx_s = -1;

        for (; idx_g != static_cast<int>(g.size()); ++idx_g) {

            do {
                ++idx_s;
                if (idx_s == static_cast<int>(s.size())) {
                    return idx_g;
                }

            } while (s[idx_s] < g[idx_g]);
        }

        return idx_g;
    }
};
*/


/*
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
*/