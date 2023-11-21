///*
// Approach 2-2: Advanced 1-Pass
class Solution {
  public:
    int minCost(string colors, vector<int>& neededTime)
    {
        const auto len = colors.size();

        auto cost_total = 0;
        auto cost_part = 0;
        auto time_max = 0;

        auto color_prev = 'A';
        for (auto idx = std::size_t(0); idx != colors.size(); ++idx) {

            if (colors[idx] != color_prev) {

                cost_total += cost_part;
                cost_part = 0;
                time_max = neededTime[idx];
                color_prev = colors[idx];
            }
            else {

                if (time_max < neededTime[idx]) {
                    cost_part += time_max;
                    time_max = neededTime[idx];
                }
                else {
                    cost_part += neededTime[idx];
                }
            }
        }

        cost_total += cost_part;

        return cost_total;
    }
};
//*/


/*
// Approach 2-1: Advanced 1-Pass
class Solution {
  public:
    int minCost(string colors, vector<int>& neededTime)
    {
        const auto len = colors.size();

        auto res = 0;
        auto max = neededTime[0];
        for (auto idx = std::size_t(1); idx != len; ++idx) {

            if (colors[idx - 1] != colors[idx]) {
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
*/


/*
// Approach 1: Two pointers
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