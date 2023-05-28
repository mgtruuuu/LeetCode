#include <algorithm>
#include <vector>

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        std::vector<int> min_cost_seq(cost.size() + 1);
        min_cost_seq[0] = 0;
        min_cost_seq[1] = 0;

        for (auto idx = 2; idx != min_cost_seq.size(); ++idx) {
            min_cost_seq[idx] = std::min(min_cost_seq[idx - 2] + cost[idx - 2], min_cost_seq[idx - 1] + cost[idx - 1]);
        }

        return min_cost_seq.back();
        
    }
};