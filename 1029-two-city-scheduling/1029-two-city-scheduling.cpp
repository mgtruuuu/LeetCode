class Solution {
  public:
    int twoCitySchedCost(vector<vector<int>>& costs)
    {
        std::sort(costs.begin(), costs.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return (a.front() - a.back() < b.front() - b.back());
        });

        auto min_cost = 0;

        const auto len = costs.size();
        const auto len_half = std::size_t(costs.size() * 0.5);

        for (auto idx = std::size_t(0); idx != len_half; ++idx) {
            min_cost += costs[idx].front() + costs[idx + len_half].back();
        }

        return min_cost;
    }
};