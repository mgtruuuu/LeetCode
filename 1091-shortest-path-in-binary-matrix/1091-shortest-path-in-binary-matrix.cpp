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