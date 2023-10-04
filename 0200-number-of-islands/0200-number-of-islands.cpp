/*
// Approach #1 - 1 : DFS
class Solution {
  private:
    void dfs(const int r, const int c, const std::vector<std::vector<char>>& grid,
             std::vector<std::vector<bool>>& visited)
    {
        if (grid[r][c] == '0' || visited[r][c] == true) {
            return;
        }

        visited[r][c] = true;

        if (0 < r && visited[r - 1][c] == false) {
            dfs(r - 1, c, grid, visited);
        }

        if (r < static_cast<int>(grid.size()) - 1 && visited[r + 1][c] == false) {
            dfs(r + 1, c, grid, visited);
        }

        if (0 < c && visited[r][c - 1] == false) {
            dfs(r, c - 1, grid, visited);
        }

        if (c < static_cast<int>(grid.front().size()) - 1 && visited[r][c + 1] == false) {
            dfs(r, c + 1, grid, visited);
        }
    }

  public:
    int numIslands(vector<vector<char>>& grid)
    {
        std::vector<std::vector<bool>> visited(len_row, std::vector<bool>(len_col, false));

        auto num_islands = 0;

        for (auto r = 0; r != static_cast<int>(grid.size()); ++r) {
            for (auto c = 0; c != static_cast<int>(grid.front().size()); ++c) {

                if (grid[r][c] == '1' && visited[r][c] == false) {

                    ++num_islands;
                    dfs(r, c, grid, visited);
                }
            }
        }

        return num_islands;
    }
};
*/


/*
// Approach #1 - 2 : DFS
class Solution {
  private:
    void dfs(const int r, const int c, std::vector<std::vector<char>>& grid)
    {
        if (grid[r][c] == '0') {
            return;
        }

        grid[r][c] = '0';

        if (0 < r) {
            dfs(r - 1, c, grid);
        }

        if (r < static_cast<int>(grid.size()) - 1) {
            dfs(r + 1, c, grid);
        }

        if (0 < c) {
            dfs(r, c - 1, grid);
        }

        if (c < static_cast<int>(grid.front().size()) - 1) {
            dfs(r, c + 1, grid);
        }
    }

  public:
    int numIslands(vector<vector<char>>& grid)
    {
        auto num_islands = 0;

        for (auto r = 0; r != static_cast<int>(grid.size()); ++r) {
            for (auto c = 0; c != static_cast<int>(grid.front().size()); ++c) {

                if (grid[r][c] == '1') {

                    ++num_islands;
                    dfs(r, c, grid);
                }
            }
        }

        return num_islands;
    }
};
*/

/*
// Approach #2: BFS
class Solution {
  public:
    int numIslands(vector<vector<char>>& grid)
    {
        std::queue<std::pair<int, int>> q;
        auto num_islands = 0;

        for (auto r = 0; r != static_cast<int>(grid.size()); ++r) {
            for (auto c = 0; c != static_cast<int>(grid.front().size()); ++c) {

                if (grid[r][c] == '0') {
                    continue;
                }

                q.emplace(r, c);
                ++num_islands;

                while (q.empty() == false) {

                    const auto rc = q.front();
                    q.pop();

                    if (grid[rc.first][rc.second] == '0') {
                        continue;
                    }
                    
                    grid[rc.first][rc.second] = '0';

                    if (0 < rc.first) {
                        q.emplace(rc.first - 1, rc.second);
                    }

                    if (rc.first < static_cast<int>(grid.size()) - 1) {
                        q.emplace(rc.first + 1, rc.second);
                    }

                    if (0 < rc.second) {
                        q.emplace(rc.first, rc.second - 1);
                    }

                    if (rc.second < static_cast<int>(grid.front().size()) - 1) {
                        q.emplace(rc.first, rc.second + 1);
                    }
                }
            }
        }

        return num_islands;
    }
};
*/


///*
// Approach #3: Union Find (aka Disjoint Set)
class UnionFind {
  private:
    std::vector<int> m_parents;
    std::vector<int> m_ranks;
    int m_num_islands;

  public:
    UnionFind(const int len) : m_num_islands{ len }
    {
        m_parents.resize(len);
        m_ranks.resize(len);
        for (auto i = 0; i != len; ++i) {
            m_parents[i] = i;
            m_ranks[i] = 1;
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

        --m_num_islands;
    }

    bool isConnected(const int x, const int y)
    {
        return find(x) == find(y);
    }

    int getNumIslands() const
    {
        return m_num_islands;
    }
};

class Solution {
  private:
    int get1DIndex(int r, int c, const int len_col)
    {
        return len_col * r + c;
    }

  public:
    int numIslands(vector<vector<char>>& grid)
    {
        const auto len_row = static_cast<int>(grid.size());
        const auto len_col = static_cast<int>(grid.front().size());
        auto num_zeros = 0;
        
        UnionFind uf{ len_row * len_col };

        for (auto r = 0; r != len_row; ++r) {
            for (auto c = 0; c != len_col; ++c) {

                if (grid[r][c] == '0') {
                    
                    ++num_zeros;
                    continue;
                }

                const auto idx = get1DIndex(r, c, len_col);

                if (0 < r && grid[r - 1][c] == '1') {
                    uf.unionSet(idx, get1DIndex(r - 1, c, len_col));
                }

                if (r < len_row - 1 && grid[r + 1][c] == '1') {
                    uf.unionSet(idx, get1DIndex(r + 1, c, len_col));
                }

                if (0 < c && grid[r][c - 1] == '1') {
                    uf.unionSet(idx, get1DIndex(r, c - 1, len_col));
                }

                if (c < len_col - 1 && grid[r][c + 1] == '1') {
                    uf.unionSet(idx, get1DIndex(r, c + 1, len_col));
                }
            }
        }

        return uf.getNumIslands() - num_zeros;
    }
};
//*/