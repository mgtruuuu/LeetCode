class UnionFind {
  private:
    std::vector<int> m_parents;

  public:
    UnionFind(const int len)
    {
        m_parents.resize(len);

        for (auto idx = 0; idx != len; ++idx) {
            m_parents[idx] = idx;
        }
    }

    int find(int x)
    {
        while (x != m_parents[x]) {
            x = m_parents[x];
        }

        return x;
    }

    bool unionSet(const int x, const int y)
    {
        const auto root_x = find(x);
        const auto root_y = find(y);

        if (root_x == root_y) {
            return false;
        }
        else {

            m_parents[root_y] = root_x;

            return true;
        }
    }
};

class Solution {
  public:
    bool validTree(int n, vector<vector<int>>& edges)
    {
        if ((n - 1) != static_cast<int>(edges.size())) {
            return false;
        }

        UnionFind uf{ n };

        for (const auto& edge : edges) {
            if (uf.unionSet(edge.front(), edge.back()) == false) {
                return false;
            }
        }

        return true;
    }
};