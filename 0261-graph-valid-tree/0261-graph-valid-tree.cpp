/*

Recall that a graph, G, is a tree iff the following two conditions are met:

G is fully connected. In other words, for every pair of nodes in G, there is a path between them.
G contains no cycles. In other words, there is exactly one path between each pair of nodes in G.


Going by this definition, our algorithm needs to do the following:

Check whether or not there are n - 1 edges. If there's not, then return false.
Check whether or not the graph is fully connected. Return true if it is, false if otherwise.

*/



/*
// Approach 1 - 1 : Graph Theory + Iterative DFS + Deleting the opposite direction edges from the adjacency list
class Solution {
  public:
    bool validTree(int n, vector<vector<int>>& edges)
    {
        std::vector<std::vector<int>> adjacent_mat(n, std::vector<int>(n, 0));
        for (const auto& edge : edges) {
            adjacent_mat[edge.front()][edge.back()] = adjacent_mat[edge.back()][edge.front()] = 1;
        }
        std::vector<bool> visited(n, false);

        std::stack<int> s;
        auto num_nonvisited = n;
        s.push(0);
        visited[0] = true;
        --num_nonvisited;

        while (s.empty() == false) {

            const auto parent = s.top();
            s.pop();

            for (auto child = 0; child != n; ++child) {

                if (adjacent_mat[parent][child] == 0) {
                    continue;
                }

                if (visited[child] == true) {
                    return false;
                }
                else {
                    adjacent_mat[child][parent] = 0;
                    s.push(child);
                    visited[child] = true;
                    --num_nonvisited;
                }
            }
        }

        return num_nonvisited == 0 ? true : false;
    }
};
*/

/*
// Approach 1 - 2 : Graph Theory + Iterative DFS + Using a seen map that also keeps track of the "parent" node that we
// got to a node from
class Solution {
  public:
    bool validTree(int n, vector<vector<int>>& edges)
    {
        std::vector<std::vector<int>> adjacent_list(n);
        for (const auto& edge : edges) {
            adjacent_list[edge.front()].push_back(edge.back());
            adjacent_list[edge.back()].push_back(edge.front());
        }
        std::unordered_map<int, int> self2parent;
        auto num_nonvisited = n;

        std::stack<int> s;
        s.push(0);
        self2parent[0] = 0;
        --num_nonvisited;
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
                --num_nonvisited;
            }
        }

        return num_nonvisited == 0 ? true : false;
    }
};
*/



/*
// Approach 2 - 1 : Advanced Graph Theory + Iterative DFS
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
        std::unordered_set<int> visited;

        std::stack<int> s;
        s.push(0);
        visited.insert(0);
        while (s.empty() == false) {

            const auto parent = s.top();
            s.pop();

            for (const auto child : adjacent_list[parent]) {

                if (visited.find(child) == visited.end()) {
                    s.push(child);
                    visited.insert(child);
                }
            }
        }

        return static_cast<int>(visited.size()) == n ? true : false;
    }
};
*/


///*
// Approach 2 - 2 : Advanced Graph Theory + Iterative DFS
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
        std::unordered_set<int> visited;

        std::queue<int> q;
        q.push(0);
        visited.insert(0);
        while (q.empty() == false) {

            const auto parent = q.front();
            q.pop();

            for (const auto child : adjacent_list[parent]) {

                if (visited.find(child) == visited.end()) {
                    q.push(child);
                    visited.insert(child);
                }
            }
        }

        return static_cast<int>(visited.size()) == n ? true : false;
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