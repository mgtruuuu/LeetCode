
/*
class Solution {
  private:
    void allPathsSourceTargetHelper(const std::vector<std::vector<int>>& graph, const int node, std::vector<int>& path,
                                    std::vector<std::vector<int>>& paths)
    {
        if (node == graph.size() - 1) {

            paths.push_back(path);

            return;
        }

        for (const auto neighbor : graph[node]) {
            
            path.push_back(neighbor);
            allPathsSourceTargetHelper(graph, neighbor, path, paths);
            path.pop_back();
        }
    }

  public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        auto path = std::vector<int>{ 0 };
        auto paths = std::vector<std::vector<int>>();

        allPathsSourceTargetHelper(graph, 0, path, paths);

        return paths;
    }
};
*/




class Solution {
  private:
    void dp(const std::vector<std::vector<int>>& graph, const int node,
            std::unordered_map<int, std::vector<std::vector<int>>>& source2paths)
    {
        if (source2paths.find(node) != source2paths.end()) {

            return;
        }

        if (node == graph.size() - 1) {

            source2paths[node] = std::vector<std::vector<int>>{ { static_cast<int>(graph.size() - 1) } };

            return;
        }

        auto union_neighbors = std::vector<std::vector<int>>();
        for (const auto neighbor : graph[node]) {

            dp(graph, neighbor, source2paths);

            union_neighbors.reserve(union_neighbors.size() + source2paths[neighbor].size());
            for (const auto& paths : source2paths[neighbor]) {

                auto path_to_insert = std::vector<int>(paths.size() + 1);
                path_to_insert.front() = node;
                memcpy(path_to_insert.data() + 1, paths.data(), sizeof(int) * paths.size());
                
                union_neighbors.push_back(path_to_insert);
            }
        }

        source2paths[node] = union_neighbors;
    }

  public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        std::unordered_map<int, std::vector<std::vector<int>>> source2paths;

        dp(graph, 0, source2paths);

        return source2paths[0];
    }
};
