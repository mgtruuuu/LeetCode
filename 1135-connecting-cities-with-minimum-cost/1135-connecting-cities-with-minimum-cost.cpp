// Approach 1: Minimum Spanning Tree (Using Prim's algorithm)
class Solution {

    using Node = int;
    using Weight = int;
    using MyVec = std::pair<Weight, Node>;

  public:
    int minimumCost(int n, vector<vector<int>>& connections)
    {
        std::vector<std::vector<MyVec>> adj_list(n);
        for (const auto& connection : connections) {
            adj_list[connection[0] - 1].emplace_back(connection[2], connection[1] - 1);
            adj_list[connection[1] - 1].emplace_back(connection[2], connection[0] - 1);
        }

        std::priority_queue<MyVec, std::vector<MyVec>, std::greater<MyVec>> pq;
        std::vector<int> visited(n, false);

        auto count = 0;
        auto sum = 0;

        pq.emplace(0, 0);

        while (pq.empty() == false) {

            const auto node = pq.top();
            pq.pop();

            if (visited[node.second] == true) {
                continue;
            }

            visited[node.second] = true;
            ++count;
            sum += node.first;

            for (const auto& my_vec : adj_list[node.second]) {
                pq.push(my_vec);
            }
        }

        return (count == n) ? sum : -1;
    }
};