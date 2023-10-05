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
        
        --m_num_components;
    }

    bool isAllConnected() const
    {
        return (m_num_components == 1);
    }
};

class Solution {
  public:
    int earliestAcq(vector<vector<int>>& logs, int n)
    {
        if (static_cast<int>(logs.size()) < n - 1) {
            return -1;
        }
        
        UnionFind uf{ n };

        std::sort(logs.begin(), logs.end(),
                  [](const std::vector<int>& a, const std::vector<int>& b) { return (a.front() < b.front()); });

        for (const auto& log : logs) {

            uf.unionSet(log[1], log[2]);

            if (uf.isAllConnected() == true) {
                return log.front();
            }
        }

        return -1;
    }
};