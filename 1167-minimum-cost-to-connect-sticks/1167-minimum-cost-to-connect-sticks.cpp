class Solution {
  public:
    int connectSticks(vector<int>& sticks)
    {
        if (sticks.size() < std::size_t(2)) {
            return 0;
        }

        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (const auto stick : sticks) {
            pq.push(stick);
        }

        auto sum_cost = 0;
        while (pq.size() != std::size_t(1)) {

            const auto max_first = pq.top();
            pq.pop();
            const auto max_second = pq.top();
            pq.pop();

            const auto cost = max_first + max_second;
            sum_cost += cost;
            pq.push(cost);
        }

        return sum_cost;
    }
};