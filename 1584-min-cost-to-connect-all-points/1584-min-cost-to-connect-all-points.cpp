///*
// Approach 1: Kruskal's Algorithm
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

        if (m_ranks[root_x] < m_ranks[root_y]) {
            m_parents[root_x] = root_y;
        }
        else if (m_ranks[root_x] > m_ranks[root_y]) {
            m_parents[root_y] = root_x;
        }
        else {
            m_parents[root_y] = root_x;
            ++m_ranks[root_x];
        }

        return true;
    }
};

class Solution {

    using Distance = int;
    using Indices = std::pair<int, int>; // index of points
    using Edge = std::pair<Distance, Indices>;

  private:
    int getManhattanDist(const std::vector<int>& pt_a, const std::vector<int>& pt_b) const
    {
        return abs(pt_a.front() - pt_b.front()) + abs(pt_a.back() - pt_b.back());
    }

  public:
    int minCostConnectPoints(vector<vector<int>>& points)
    {
        const auto num_points = static_cast<int>(points.size());

        UnionFind uf{ num_points };
        std::vector<Edge> edges;
        edges.reserve(std::size_t(num_points * (num_points - 1) * 0.5));

        for (auto i = 0; i != num_points; ++i) {
            for (auto j = i + 1; j != num_points; ++j) {
                edges.emplace_back(getManhattanDist(points[i], points[j]), std::make_pair(i, j));
            }
        }

        auto count = 0;
        auto sum = 0;
        std::sort(edges.begin(), edges.end());
        for (const auto& edge : edges) {
                        
            if (uf.unionSet(edge.second.first, edge.second.second) == true) {

                ++count;
                sum += edge.first;
            }

            if (count == num_points - 1) {
                break;
            }
        }

        return sum;
    }
};
//*/