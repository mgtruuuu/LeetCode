/*
// Approach 1: Minimum Spanning Tree (Using Kruskal's algorithm)
class DisjointSet {
  private:
    int m_num_components;
    std::vector<int> m_parents;
    std::vector<int> m_ranks;

  public:
    DisjointSet(const int num_nodes) : m_num_components{ num_nodes }
    {
        m_parents.resize(num_nodes);
        m_ranks.resize(num_nodes);
        for (auto i = 0; i != num_nodes; ++i) {
            m_parents[i] = i;
            m_ranks[i] = 0;
        }
    }

    int find(const int x)
    {
        return (x == m_parents[x]) ? x : (m_parents[x] = find(m_parents[x]));
    }

    bool unionSet(int x, int y)
    {
        x = find(x);
        y = find(y);

        if (x == y) {
            return false;
        }

        if (m_ranks[x] < m_ranks[y]) {
            m_parents[x] = y;
        }
        else if (m_ranks[x] > m_ranks[y]) {
            m_parents[y] = x;
        }
        else {
            m_parents[y] = x;
            ++m_ranks[x];
        }

        --m_num_components;
        return true;
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
  private:
    using Edge = std::vector<int>; // Node Node Weight
    struct EdgeComp {
        bool operator()(const Edge& lhs, const Edge& rhs)
        {
            return lhs.back() > rhs.back();
        }
    };

  public:
    int minimumCost(int n, vector<vector<int>>& connections)
    {
        std::priority_queue<Edge, std::vector<Edge>, EdgeComp> pq;
        std::vector<int> visited(n, false);

        DisjointSet disj{ n };

        auto count = 0;
        auto sum = 0;

        for (const auto& connection : connections) {
            pq.push({ connection[0] - 1, connection[1] - 1, connection[2] });
        }

        while (pq.empty() == false) {

            const auto edge = pq.top();
            pq.pop();

            if (disj.unionSet(edge[0], edge[1]) == false) {
                continue;
            }

            sum += edge[2];
            if (++count == n - 1) {
                break;
            }
        }

        return (count == n - 1) ? sum : -1;
    }
};
*/


///*
// Approach 2: Minimum Spanning Tree (Using Prim's algorithm)
class Solution {

    using Node = int;
    using Weight = int;
    using MyVec = std::pair<Weight, Node>;

  public:
    int minimumCost(int n, vector<vector<int>>& connections)
    {
        std::vector<std::vector<MyVec>> adj_list(n);
        for (const auto& connection : connections) {
            adj_list[connection[0] - 1].emplace_back(connection[2], connection[1] - 1);
            adj_list[connection[1] - 1].emplace_back(connection[2], connection[0] - 1);
        }

        std::priority_queue<MyVec, std::vector<MyVec>, std::greater<MyVec>> pq;
        std::vector<int> visited(n, false);

        auto count = 0;
        auto sum = 0;

        pq.emplace(0, 0);

        while (pq.empty() == false) {

            const auto node = pq.top();
            pq.pop();

            if (visited[node.second] == true) {
                continue;
            }

            visited[node.second] = true;
            ++count;
            sum += node.first;

            for (const auto& my_vec : adj_list[node.second]) {
                pq.push(my_vec);
            }
        }

        return (count == n) ? sum : -1;
    }
};
//*/