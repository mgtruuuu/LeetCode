class Solution {
    using Vec = std::pair<int, int>;  // node and dist
    using Node = std::pair<int, int>; // time and node

  public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        std::vector<std::vector<Vec>> adj_list(n);
        for (const auto& time : times) {
            adj_list[time[0] - 1].emplace_back(time[1] - 1, time[2]);
        }

        std::vector<bool> visited(n, false);
        std::vector<int> shortest(n, INT_MAX);
        shortest[k - 1] = 0;

        std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
        pq.emplace(shortest[k - 1], k - 1);

        while (pq.empty() == false) {

            const auto node_time = pq.top().first;
            const auto node_idx = pq.top().second;
            pq.pop();

            if (visited[node_idx] == true) {
                continue;
            }
            visited[node_idx] = true;

            for (const auto& vec : adj_list[node_idx]) {

                if (visited[vec.first] == false && node_time + vec.second < shortest[vec.first]) {
                    
                    shortest[vec.first] = node_time + vec.second;
                    pq.emplace(shortest[vec.first], vec.first);
                }
            }
        }

        const auto max_shortest = *std::max_element(shortest.begin(), shortest.end());

        return max_shortest == INT_MAX ? -1 : max_shortest;
    }
};