///*
// Approach 3: Advanced Graph Theory + Union Find
class UnionFind {
  private:
    std::vector<int> m_parents;
    std::vector<int> m_ranks;

  public:
    UnionFind(const int len)
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

    bool unionSet(const int x, const int y)
    {
        const auto root_x = find(x);
        const auto root_y = find(y);

        if (root_x == root_y) {
            return false;
        }
        else if (root_x < root_y) {
            m_parents[root_x] = root_y;
        }
        else {
            m_parents[root_y] = root_x;
        }

        return true;
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
//*/