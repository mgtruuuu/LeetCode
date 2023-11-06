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