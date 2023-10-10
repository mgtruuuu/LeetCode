class Solution {
  public:
    int minCost(string colors, vector<int>& neededTime)
    {
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


/*
class Solution {
  public:
    int minCost(string colors, vector<int>& neededTime)
    {
        const auto len = colors.size();

        auto sum_cost = 0;
        auto idx_lhs = std::size_t(0);

        auto idx_rhs = std::size_t(1);
        while (idx_rhs != colors.size()) {

            auto cost_delete = 0;
            auto cost_max = neededTime[idx_lhs];
            while (idx_rhs != colors.size() && colors[idx_lhs] == colors[idx_rhs]) {

                if (cost_max < neededTime[idx_rhs]) {
                    cost_delete += cost_max;
                    cost_max = neededTime[idx_rhs];
                }
                else {
                    cost_delete += neededTime[idx_rhs];
                }

                if (++idx_rhs == len) {
                    return sum_cost + cost_delete;
                }
            }

            idx_lhs = idx_rhs++;
            sum_cost += cost_delete;
        }

        return sum_cost;
    }
};
*/