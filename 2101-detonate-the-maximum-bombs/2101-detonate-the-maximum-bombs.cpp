class Solution {
  private:
    bool isConnected(const std::vector<int>& from, const std::vector<int>& to)
    {
        const auto delta_x = int64_t(from[0] - to[0]);
        const auto delta_y = int64_t(from[1] - to[1]);

        return delta_x * delta_x + delta_y * delta_y <= int64_t(from[2]) * from[2];
    }

  public:
    int maximumDetonation(vector<vector<int>>& bombs)
    {
        const auto len_bombs = static_cast<int>(bombs.size());

        std::vector<std::vector<int>> list_adj(len_bombs);

        for (auto i = 0; i != len_bombs; ++i) {
            for (auto j = 0; j != len_bombs; ++j) {

                if (i == j) {
                    continue;
                }

                if (isConnected(bombs[i], bombs[j]) == true) {
                    list_adj[i].push_back(j);
                }
            }
        }

        auto maximum_detonation = INT_MIN;
        for (auto i = 0; i != len_bombs; ++i) {

            auto temp = 0;
            std::vector<bool> visited(len_bombs, false);
            std::stack<int> s;
            
            visited[i] = true;
            s.push(i);
            while (s.empty() == false) {

                const auto node = s.top();
                s.pop();

                ++temp;

                for (const auto neighbor : list_adj[node]) {

                    if (visited[neighbor] == false) {

                        visited[neighbor] = true;
                        s.push(neighbor);
                    }
                }
            }

            if (maximum_detonation < temp) {
                maximum_detonation = temp;
            }
        }

        return maximum_detonation;
    }
};