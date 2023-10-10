using AMinusB = int;
using B = int;
using Pair = std::pair<AMinusB, B>;

class Solution {
  public:
    int twoCitySchedCost(vector<vector<int>>& costs)
    {
        const auto len = costs.size();

        std::vector<Pair> pairs;
        pairs.reserve(len);
        for (const auto& cost : costs) {
            pairs.emplace_back(cost.front() - cost.back(), cost.back());
        }

        std::sort(pairs.begin(), pairs.end());

        auto min_cost = 0;
        auto idx = 0;
        for (; idx != len * 0.5; ++idx) {
            min_cost += pairs[idx].first + pairs[idx].second;
        }
        for (; idx != len; ++idx) {
            min_cost += pairs[idx].second;
        }

        return min_cost;
    }
};