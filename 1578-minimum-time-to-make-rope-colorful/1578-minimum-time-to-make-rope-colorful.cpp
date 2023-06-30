class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
     
        const auto len = colors.size();
        
        auto prev_color = 'A';
        auto max = 0;
        auto res = 0;
        for (auto idx = std::size_t(0); idx != len; ++idx) {
            if (prev_color != colors[idx]) {
                prev_color = colors[idx];
                max = neededTime[idx];
            }
            else if (max < neededTime[idx]) {
                res += max;
                max = neededTime[idx];
            }
            else {
                res += neededTime[idx];
            }
        }
        
        return res;
    }
};