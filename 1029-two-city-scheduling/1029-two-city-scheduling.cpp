class Solution {
  public:
    int twoCitySchedCost(vector<vector<int>>& costs)
    {
        std::sort(costs.begin(), costs.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return (a.front() - a.back() < b.front() - b.back());
        });

        auto sum = 0;

        auto idx = std::size_t(0);
        for (; idx != costs.size() / 2; ++idx) {
            sum += costs[idx].front();
        }

        for (; idx != costs.size(); ++idx) {
            sum += costs[idx].back();
        }

        return sum;
    }
};