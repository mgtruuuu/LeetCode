/*
// Approach 1: DFS: Iterative
class Solution {
  public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        std::vector<std::vector<int>> adj_list(n);
        for (const auto& edge : edges) {

            adj_list[edge.front()].push_back(edge.back());
            adj_list[edge.back()].push_back(edge.front());
        }

        std::vector<bool> visited(n, false);

        std::stack<int> s;
        s.push(source);
        visited[source] = true;

        while (s.empty() == false) {

            const auto node = s.top();
            s.pop();
            
            if (node == destination) {
                return true;
            }

            for (const auto neighbor : adj_list[node]) {

                if (visited[neighbor] == false) {

                    s.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        return false;
    }
};
*/


/*
// Approach 2: DFS: Recursive
class Solution {
  private:
    bool bfs(const std::vector<std::vector<int>>& adj_list, const int destination, const int node,
             std::vector<bool>& visited)
    {
        if (node == destination) {
            return true;
        }        
        
        if (visited[node] == true) {
            return false;
        }

        visited[node] = true;

        for (const auto neighbor : adj_list[node]) {
            
            if (bfs(adj_list, destination, neighbor, visited) == true) {
                return true;
            }
        }

        return false;
    }

  public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        std::vector<std::vector<int>> adj_list(n);
        for (const auto& edge : edges) {

            adj_list[edge.front()].push_back(edge.back());
            adj_list[edge.back()].push_back(edge.front());
        }

        std::vector<bool> visited(n, false);

        return bfs(adj_list, destination, source, visited);
    }
};
*/


/*
// Approach 3: BFS
class Solution {
  public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        std::vector<std::vector<int>> adj_list(n);
        for (const auto& edge : edges) {

            adj_list[edge.front()].push_back(edge.back());
            adj_list[edge.back()].push_back(edge.front());
        }

        std::vector<bool> visited(n, false);

        std::queue<int> q;
        q.push(source);
        visited[source] = true;

        while (q.empty() == false) {

            const auto node = q.front();
            q.pop();

            if (node == destination) {
                return true;
            }

            for (const auto neighbor : adj_list[node]) {

                if (visited[neighbor] == false) {

                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        return false;
    }
};
*/


///*
// Approach 4: Disjoint Set Union (DSU)
class UnionFind {
  private:
    std::vector<int> m_parents;
    std::vector<int> m_ranks;
    // int m_num_components;

  public:
    UnionFind(const int len) //: m_num_components{ len }
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
        if (x == m_parents[x]) {
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
    }

    bool isConnected(const int x, const int y)
    {
        return find(x) == find(y);
    }

    // int getNumComponents() const
    // {
    //     return m_num_components;
    // }
};

class Solution {
  public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        UnionFind uf{ n };

        for (const auto& edge : edges) {
            uf.unionSet(edge.front(), edge.back());
        }

        return uf.isConnected(source, destination);
    }
};
//*/