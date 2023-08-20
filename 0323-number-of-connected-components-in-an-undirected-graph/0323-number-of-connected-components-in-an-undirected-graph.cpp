class UnionFind {
  private:
    std::vector<int> m_parents;
    std::vector<int> m_ranks;
    int m_num_components;

  public:
    UnionFind(const int num_nodes) : m_num_components{ num_nodes }
    {
        m_parents.resize(num_nodes);
        m_ranks.resize(num_nodes);

        for (auto idx = 0; idx != num_nodes; ++idx) {
            m_parents[idx] = idx;
            m_ranks[idx] = 1;
        }
    }

    int find(int x)
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

        --m_num_components;

        if (root_x < root_y) {
            m_parents[root_x] = root_y;
        }
        else if (root_y < root_x) {
            m_parents[root_y] = root_x;
        }
        else {
            m_parents[root_x] = root_y;
            ++m_ranks[root_y];
        }
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