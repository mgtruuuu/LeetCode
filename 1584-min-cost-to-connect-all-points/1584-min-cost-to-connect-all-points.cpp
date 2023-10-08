/*
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
*/


///*
// Approach 2: Prim's Algorithm (Optimized)
class Solution {
  private:
    int getManhattanDist(const std::vector<int>& pt_a, const std::vector<int>& pt_b) const
    {
        return abs(pt_a.front() - pt_b.front()) + abs(pt_a.back() - pt_b.back());
    }

  public:
    int minCostConnectPoints(vector<vector<int>>& points)
    {
        const auto num_points = static_cast<int>(points.size());

        std::vector<bool> visited(num_points, false);
        std::vector<int> min_dist(num_points, std::numeric_limits<int>::max());
        min_dist[0] = 0;
        
        auto sum_cost = 0;
        auto num_vecs = 0;
        while (num_vecs++ < num_points) {

            auto idx_min = -1;
            auto dist_min = std::numeric_limits<int>::max();

            // for nodes not in MST
            for (auto idx_node = 0; idx_node != num_points; ++idx_node) {

                if (visited[idx_node] == false && min_dist[idx_node] < dist_min) {

                    idx_min = idx_node;
                    dist_min = min_dist[idx_node];
                }
            }

            sum_cost += dist_min;
            visited[idx_min] = true;

            for (auto idx_node = 0; idx_node != num_points; ++idx_node) {

                if (visited[idx_node] == true) {
                    continue;
                }

                const auto temp = getManhattanDist(points[idx_min], points[idx_node]);

                if (temp < min_dist[idx_node]) {
                    min_dist[idx_node] = temp;
                }
            }
        }

        return sum_cost;
    }
};
//*/