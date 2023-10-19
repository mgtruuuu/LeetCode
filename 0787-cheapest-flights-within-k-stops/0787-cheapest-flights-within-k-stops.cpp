/*
// Approach 2: Bellman Ford
class Solution {
  public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        std::vector<int> prices(n, INT_MAX);
        prices[src] = 0;

        ++k;
        while (k-- != 0) {

            std::vector<int> temp = prices;

            for (const auto& flight : flights) {

                if (prices[flight[0]] != INT_MAX && prices[flight[0]] + flight[2] < temp[flight[1]]) {
                    temp[flight[1]] = prices[flight[0]] + flight[2];
                }
            }

            prices = temp;
        }

        return (prices[dst] == INT_MAX) ? -1 : prices[dst];
    }
};
*/


// Approach 3: Dijkstra
class Solution {

    // {end_point, weight}
    using MyVec = std::pair<int, int>;

    // {dist_from_src_node, node, number_of_stops_from_src_node}
    using MyTuple = std::tuple<int, int, int>;

  public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        std::vector<std::vector<MyVec>> adj_list(n);
        for (const auto& flight : flights) {
            adj_list[flight[0]].emplace_back(flight[1], flight[2]);
        }

        std::vector<int> stops(n, INT_MAX);
        std::priority_queue<MyTuple, std::vector<MyTuple>, std::greater<MyTuple>> pq;

        pq.push({ 0, src, 0 });

        while (pq.empty() == false) {

            const auto dist = std::get<0>(pq.top());
            const auto node = std::get<1>(pq.top());
            const auto num_stops = std::get<2>(pq.top());
            pq.pop();

            if (k + 1 < num_stops || stops[node] < num_stops) {
                continue;
            }
            stops[node] = num_stops;
            
            if (node == dst) {
                return dist;
            }

            for (const auto& my_vec : adj_list[node]) {
                pq.push({ dist + my_vec.second, my_vec.first, num_stops + 1 });
            }
        }

        return -1;
    }
};