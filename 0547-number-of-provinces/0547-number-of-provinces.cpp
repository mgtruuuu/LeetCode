class UnionFind {
  private:
    int m_len;
    std::vector<int> m_parents;
    std::vector<int> m_ranks;

  public:
    UnionFind(const int len) : m_len{ len }
    {
        m_parents.resize(len);
        m_ranks.resize(len);

        for (auto idx = 0; idx != len; ++idx) {
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

        --m_len;
    }

    bool isConnected(const int x, const int y)
    {
        return (find(x) == find(y));
    }

    int getLength() const
    {
        return m_len;
    }
};

class Solution {
  public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        const auto len = static_cast<int>(isConnected.size());

        UnionFind uf{ len };

        for (auto x = 0; x != len; ++x) {
            for (auto y = x + 1; y != len; ++y) {

                if (isConnected[x][y] == 1) {
                    uf.unionSet(x, y);
                }
            }
        }

        return uf.getLength();
    }
};