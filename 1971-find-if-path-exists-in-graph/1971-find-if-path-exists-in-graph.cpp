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

    int getNumComponents() const
    {
        return m_num_components;
    }
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