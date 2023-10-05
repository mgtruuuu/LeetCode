/*
// Approach 1 - 1 : Iterative DFS
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
*/


/*
// Approach 1 - 2 : Recursive DFS
class Solution {
  private:
    void bfs(const std::vector<std::vector<int>>& adj_list, const int node, std::vector<bool>& visited)
    {
        visited[node] = true;

        for (const auto child : adj_list[node]) {

            if (visited[child] == false) {
                bfs(adj_list, child, visited);
            }
        }
    }

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

        for (auto idx = 0; idx != n; ++idx) {

            if (visited[idx] == true) {
                continue;
            }

            ++num_components;
            bfs(adj_list, idx, visited);
        }

        return num_components;
    }
};
*/


// Approach 2 : Iterative BFS
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
        std::queue<int> q;

        for (auto idx = 0; idx != n; ++idx) {

            if (visited[idx] == true) {
                continue;
            }

            ++num_components;
            q.push(idx);
            visited[idx] = true;
            while (q.empty() == false) {

                const auto node = q.front();
                q.pop();

                for (const auto child : adj_list[node]) {

                    if (visited[child] == false) {
                        q.push(child);
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