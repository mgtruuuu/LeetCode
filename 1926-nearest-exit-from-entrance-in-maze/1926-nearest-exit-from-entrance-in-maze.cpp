class Solution {
  private:
    int isCellAtBorder(const int len_row, const int len_col, const int row, const int col)
    {
        return (0 == row) || (row == len_row - 1) || (0 == col) || (col == len_col - 1);
    }

  public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance)
    {
        const auto len_row = static_cast<int>(maze.size());
        const auto len_col = static_cast<int>(maze.front().size());

        std::vector<std::vector<int>> visited(maze.size(), std::vector<int>(maze.front().size(), false));

        std::queue<std::vector<int>> q;
        q.push(entrance);
        visited[entrance[0]][entrance[1]] = true;

        auto step = 0;
        while (q.empty() == false) {

            ++step;

            auto len_q = q.size();
            while (len_q-- != 0) {

                const auto row = q.front().front();
                const auto col = q.front().back();
                q.pop();

                if (0 <= row - 1 && visited[row - 1][col] == false && maze[row - 1][col] == '.') {

                    if (isCellAtBorder(len_row, len_col, row - 1, col) == true) {
                        return step;
                    }

                    q.push({ row - 1, col });
                    visited[row - 1][col] = true;
                }

                if (row + 1 < len_row && visited[row + 1][col] == false && maze[row + 1][col] == '.') {

                    if (isCellAtBorder(len_row, len_col, row + 1, col) == true) {
                        return step;
                    }

                    q.push({ row + 1, col });
                    visited[row + 1][col] = true;
                }

                if (0 <= col - 1 && visited[row][col - 1] == false && maze[row][col - 1] == '.') {

                    if (isCellAtBorder(len_row, len_col, row, col - 1) == true) {
                        return step;
                    }

                    q.push({ row, col - 1 });
                    visited[row][col - 1] = true;
                }

                if (col + 1 < len_col && visited[row][col + 1] == false && maze[row][col + 1] == '.') {

                    if (isCellAtBorder(len_row, len_col, row, col + 1) == true) {
                        return step;
                    }

                    q.push({ row, col + 1 });
                    visited[row][col + 1] = true;
                }
            }
        }

        return -1;
    }
};