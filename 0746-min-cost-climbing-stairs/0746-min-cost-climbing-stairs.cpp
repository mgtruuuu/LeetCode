#include <algorithm>
#include <queue>
//#include <vector>

class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        std::queue<int> min_cost_seq;
        min_cost_seq.push(0);
        min_cost_seq.push(0);

        for (auto idx = 2; idx != cost.size() + 1; ++idx) {

            const auto front = min_cost_seq.front();

            min_cost_seq.pop();
            min_cost_seq.push(std::min(front + cost[idx - 2], min_cost_seq.front() + cost[idx - 1]));
        }

        return min_cost_seq.back();
    }

    // int minCostClimbingStairs(vector<int>& cost)
    // {
    //     std::vector<int> min_cost_seq(cost.size() + 1);
    //     min_cost_seq[0] = 0;
    //     min_cost_seq[1] = 0;

    //     for (auto idx = 2; idx != min_cost_seq.size(); ++idx) {
    //         min_cost_seq[idx] = std::min(min_cost_seq[idx - 2] + cost[idx - 2], min_cost_seq[idx - 1] + cost[idx -
    //         1]);
    //     }

    //     return min_cost_seq.back();
    // }
};