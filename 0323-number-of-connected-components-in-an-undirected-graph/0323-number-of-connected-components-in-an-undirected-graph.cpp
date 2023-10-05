// Approach 1: Depth-First Search (DFS)
class Solution {
  public:
    int countComponents(int n, vector<vector<int>>& edges)
    {
        std::vector<std::vector<int>> adj_list(n);
        for (const auto& edge : edges) {
            adj_list[edge.front()].push_back(edge.back());
            adj_list[edge.back()].push_back(edge.front());
        }
        std::vector<bool> visited(n, false);

        auto num_components = 0;
        std::stack<int> s;

        for (auto idx = 0; idx != n; ++idx) {

            if (visited[idx] == true) {
                continue;
            }

            ++num_components;
            s.push(idx);
            visited[idx] = true;
            while (s.empty() == false) {

                const auto node = s.top();
                s.pop();

                for (const auto child : adj_list[node]) {

                    if (visited[child] == false) {
                        s.push(child);
                        visited[child] = true;
                    }
                }
            }
        }

        return num_components;
    }
};


// Approach 1: Depth-First Search (DFS)

// Approach 2: Disjoint Set Union (DSU)