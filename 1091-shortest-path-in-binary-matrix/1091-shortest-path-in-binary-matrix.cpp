///*
// Approach 1: Breadth-first Search (BFS), Overwriting Input
class Solution {
  public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        const auto len_grid = static_cast<int>(grid.size());

        if (grid[0][0] != 0 || grid[len_grid - 1][len_grid - 1] != 0) {
            return -1;
        }

        std::queue<std::pair<int, int>> q;
        q.emplace(0, 0);
        grid[0][0] = 1;

        while (q.empty() == false) {

            const auto rc = q.front();
            q.pop();

            if (rc.first == len_grid - 1 && rc.second == len_grid - 1) {
                return grid[rc.first][rc.second];
            }

            for (auto r = rc.first - 1; r <= rc.first + 1; ++r) {

                if (r < 0 || r == len_grid) {
                    continue;
                }

                for (auto c = rc.second - 1; c <= rc.second + 1; ++c) {

                    if (c < 0 || c == len_grid) {
                        continue;
                    }

                    if (grid[r][c] == 0) {

                        q.emplace(r, c);
                        grid[r][c] = grid[rc.first][rc.second] + 1;
                    }
                }
            }
        }

        return -1;
    }
};
//*/



/*
// Approach 2-1: Breadth-first Search (Without Overwriting the Input)
class Solution {
  public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        const auto len_grid = static_cast<int>(grid.size());
        
        if (grid[0][0] != 0 || grid[len_grid - 1][len_grid - 1] != 0) {
            return -1;
        }

        std::vector<std::vector<bool>> visited(len_grid, std::vector<bool>(len_grid, false));
        
        std::queue<std::pair<int, int>> q;
        q.emplace(0, 0);
        visited[0][0] = true;
        auto len_path = 0;
  
        while (q.empty() == false) {

            ++len_path;
            auto len_q = q.size();

            while (len_q-- != 0) {

                const auto rc = q.front();
                q.pop();
                
                if (rc.first == len_grid - 1 && rc.second == len_grid - 1) {
                    return len_path;
                }

                for (auto r = rc.first - 1; r <= rc.first + 1; ++r) {
                    
                    if (r < 0 || r >= len_grid) {
                        continue;
                    }
                    
                    for (auto c = rc.second - 1; c <= rc.second + 1; ++c) {
                     
                        if (c < 0 || c >= len_grid) {
                            continue;
                        }
                        
                        if (grid[r][c] == 0 && visited[r][c] == false) {

                            q.emplace(r, c);
                            visited[r][c] = true;
                        }
                    }
                }
            }
        }

        return -1;
    }
};
*/


/*
// Approach 2-2: Breadth-first Search (Without Overwriting the Input)
class Solution {
  private:
    int get1DIndex(const int num_cols, const int r, const int c)
    {
        return r * num_cols + c;
    }

  public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        if (grid.back().back() == 1) {
            return -1;
        }

        const auto len_square = static_cast<int>(grid.size());

        auto visited = std::vector<bool>(len_square * len_square, false);
        auto distance = 0;

        std::queue<int> q;
        q.push(0);
        while (q.empty() == false) {

            ++distance;

            auto len_q = q.size();
            while (len_q-- != 0) {

                const auto row = q.front() / len_square;
                const auto col = q.front() % len_square;
                q.pop();

                if (grid[row][col] == 1) {
                    continue;
                }

                const auto idx_1d = get1DIndex(len_square, row, col);
                if (visited[idx_1d] == true) {
                    continue;
                }
                visited[idx_1d] = true;

                if (row == len_square - 1 && col == len_square - 1) {
                    return distance;
                }

                for (auto r = row - 1; r <= row + 1; ++r) {

                    if (r < 0 || r == len_square) {
                        continue;
                    }

                    for (auto c = col - 1; c <= col + 1; ++c) {

                        if (c < 0 || c == len_square) {
                            continue;
                        }

                        q.push(get1DIndex(len_square, r, c));
                    }
                }
            }
        }

        return -1;
    }
};
*/