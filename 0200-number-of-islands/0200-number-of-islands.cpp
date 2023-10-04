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

///*
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
//*/