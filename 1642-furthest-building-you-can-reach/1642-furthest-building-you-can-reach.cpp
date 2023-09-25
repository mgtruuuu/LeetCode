class Solution {
  public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders)
    {
        using my_t = unsigned long long;

        auto sum_diff_bricks = 0;
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq_diff_ladders;

        auto idx = 1;
        for (; idx != static_cast<int>(heights.size()); ++idx) {

            if (heights[idx] <= heights[idx - 1]) {
                continue;
            }

            const auto diff = heights[idx] - heights[idx - 1];

            pq_diff_ladders.push(diff);

            if (pq_diff_ladders.size() > std::size_t(ladders)) {

                sum_diff_bricks += pq_diff_ladders.top();

                pq_diff_ladders.pop();
            }

            if (bricks != 0) {
                if (bricks < sum_diff_bricks) {
                    return idx - 1;
                }
                else if (bricks == sum_diff_bricks) {
                    continue;
                }
            }
            else if (pq_diff_ladders.empty() == true) {
                return idx - 1;
            }
            else if (pq_diff_ladders.size() == std::size_t(ladders)) {
                return idx;
            }
        }

        return idx - 1; // idx == heights.size()
    }
};
