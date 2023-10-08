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