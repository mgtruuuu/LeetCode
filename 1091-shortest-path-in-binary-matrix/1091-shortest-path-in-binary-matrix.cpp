/**/
// Approach 2-1: Breadth-first Search (Without Overwriting the Input)
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