///*
// Approach #1: Coloring by Recursive DFS
constexpr auto color_a = std::numeric_limits<int>::min();
constexpr auto color_b = std::numeric_limits<int>::max();

class Solution {
  private:
    bool dfs(const int node, const std::vector<std::vector<int>>& graph, std::vector<int>& colors)
    {
        for (const auto neighbor : graph[node]) {

            if (colors[node] == colors[neighbor]) {
                return false;
            }

            if (colors[neighbor] != 0) {
                continue;
            }

            colors[neighbor] = (color_a == colors[node] ? color_b : color_a);
            if (dfs(neighbor, graph, colors) == false) {
                return false;
            }
        }

        return true;
    }

  public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        const auto num_nodes = static_cast<int>(graph.size());
        std::vector<int> colors(num_nodes, 0);

        for (auto idx = 0; idx != num_nodes; ++idx) {

            if (colors[idx] != 0) {
                continue;
            }

            colors[idx] = color_a;
            if (dfs(idx, graph, colors) == false) {
                return false;
            }
        }

        return true;
    }
};
//*/


/*
// Approach #2: Coloring by Iterative DFS
class Solution {
  public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        constexpr auto color_a = std::numeric_limits<int>::min();
        constexpr auto color_b = std::numeric_limits<int>::max();

        const auto num_nodes = static_cast<int>(graph.size());
        std::vector<int> colors(num_nodes, 0); //

        std::stack<int> s;

        for (auto idx = 0; idx != num_nodes; ++idx) {

            if (colors[idx] != 0) {
                continue;
            }

            s.push(idx);
            colors[idx] = color_a;

            while (s.empty() == false) {

                const auto node = s.top();
                s.pop();

                for (const auto neighbor : graph[node]) {

                    if (colors[node] == colors[neighbor]) {
                        return false;
                    }

                    if (colors[neighbor] == 0) {

                        s.push(neighbor);
                        colors[neighbor] = (color_a == colors[node] ? color_b : color_a);
                    }
                }
            }
        }

        return true;
    }
};
*/





/*
// Approach #3: Coloring by Iterative BFS
class Solution {
  public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        constexpr auto color_a = std::numeric_limits<int>::min();
        constexpr auto color_b = std::numeric_limits<int>::max();

        const auto num_nodes = static_cast<int>(graph.size());
        std::vector<int> colors(num_nodes, 0); //

        std::queue<int> q;

        for (auto idx = 0; idx != num_nodes; ++idx) {

            if (colors[idx] != 0) {
                continue;
            }

            q.push(idx);
            colors[idx] = color_a;

            while (q.empty() == false) {

                const auto node = q.front();
                q.pop();

                for (const auto neighbor : graph[node]) {

                    if (colors[node] == colors[neighbor]) {
                        return false;
                    }

                    if (colors[neighbor] == 0) {

                        q.push(neighbor);
                        colors[neighbor] = (color_a == colors[node] ? color_b : color_a);
                    }
                }
            }
        }

        return true;
    }
};
*/