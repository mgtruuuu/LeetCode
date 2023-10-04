/*
// Approach 1 - 1 : Graph Theory + Iterative DFS + Deleting the opposite direction edges from the adjacency list
class Solution {
  public:
    bool validTree(int n, vector<vector<int>>& edges)
    {
        if ((n - 1) != static_cast<int>(edges.size())) {
            return false;
        }

        std::vector<std::vector<int>> adjacent_mat(n, std::vector<int>(n, 0));
        for (const auto& edge : edges) {
            adjacent_mat[edge.front()][edge.back()] = adjacent_mat[edge.back()][edge.front()] = 1;
        }
        std::vector<bool> visited(n, false);

        std::stack<int> s;
        for (auto r = 0; r != n; ++r) {

            if (visited[r] == true) {
                continue;
            }

            s.push(r);
            visited[r] = true;

            while (s.empty() == false) {

                const auto node = s.top();
                s.pop();

                for (auto c = 0; c != n; ++c) {

                    if (adjacent_mat[node][c] == 0) {
                        continue;
                    }

                    if (visited[c] == true) {
                        return false;
                    }
                    else {
                        adjacent_mat[c][node] = 0;
                        s.push(c);
                        visited[c] = true;
                    }
                }
            }
        }

        return true;
    }
};
*/

///*
// Approach 1 - 2 : Graph Theory + Iterative DFS + Using a seen map that also keeps track of the "parent" node that we
// got to a node from
class Solution {
  public:
    bool validTree(int n, vector<vector<int>>& edges)
    {
        if ((n - 1) != static_cast<int>(edges.size())) {
            return false;
        }

        std::vector<std::vector<int>> adjacent_list(n);
        for (const auto& edge : edges) {
            adjacent_list[edge.front()].push_back(edge.back());
            adjacent_list[edge.back()].push_back(edge.front());
        }
        std::unordered_map<int, int> self2parent;

        std::stack<int> s;
        for (auto r = 0; r != n; ++r) {

            if (self2parent.find(r) != self2parent.end()) {
                continue;
            }

            s.push(r);
            self2parent[r] = r;

            while (s.empty() == false) {

                const auto parent = s.top();
                s.pop();

                for (const auto child : adjacent_list[parent]) {

                    if (child == self2parent[parent]) {
                        continue;
                    }

                    if (self2parent.find(child) != self2parent.end()) {
                        return false;
                    }

                    s.push(child);
                    self2parent[child] = parent;
                }
            }
        }

        return true;
    }
};
//*/

/*
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
*/