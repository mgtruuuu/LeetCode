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


/*
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
*/


// Approach 3: Disjoint Set Union (DSU)
class UnionFind {
  private:
    std::vector<int> m_parents;
    std::vector<int> m_ranks;
    int m_num_components;

  public:
    UnionFind(const int len) : m_num_components{ len }
    {
        m_parents.resize(len);
        m_ranks.resize(len);
        for (auto i = 0; i != len; ++i) {
            m_parents[i] = i;
            m_ranks[i] = 1;
        }
    }

    int find(const int x)
    {
        if (m_parents[x] == x) {
            return x;
        }

        return (m_parents[x] = find(m_parents[x]));
    }

    void unionSet(const int x, const int y)
    {
        const auto root_x = find(x);
        const auto root_y = find(y);

        if (root_x == root_y) {
            return;
        }

        if (m_ranks[root_x] < m_ranks[root_y]) {
            m_parents[root_x] = root_y;
        }
        else if (m_ranks[root_x] > m_ranks[root_y]) {
            m_parents[root_y] = root_x;
        }
        else {
            m_parents[root_x] = root_y;
            ++m_ranks[root_y];
        }

        --m_num_components;
    }

    bool isConnected(const int x, const int y)
    {
        return (find(x) == find(y));
    }

    int getNumComponents() const
    {
        return m_num_components;
    }
};

class Solution {
  public:
    int countComponents(int n, vector<vector<int>>& edges)
    {
        UnionFind uf{ n };
        for (const auto& edge : edges) {
            uf.unionSet(edge.front(), edge.back());
        }

        return uf.getNumComponents();
    }
};