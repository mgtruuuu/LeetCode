///*
// Approach 1-1: Better Counting
class Solution {
  public:
    int islandPerimeter(vector<vector<int>>& grid)
    {
        const auto num_rows = static_cast<int>(grid.size());
        const auto num_cols = static_cast<int>(grid.front().size());

        auto perimeter = 0;
        for (auto row = 0; row < num_rows; ++row) {
            for (auto col = 0; col < num_cols; ++col) {

                if (grid[row][col] == 0) {
                    continue;
                }

                perimeter += 4;

                if (row > 0 && grid[row - 1][col] == 1) {
                    perimeter -= 2;
                }

                if (col > 0 && grid[row][col - 1] == 1) {
                    perimeter -= 2;
                }
            }
        }

        return perimeter;
    }
};
//*/


/*
// Approach 1-2: Better Counting <----------- My sol
class Solution {
  public:
    int islandPerimeter(vector<vector<int>>& grid)
    {
        const auto num_row = static_cast<int>(grid.size());
        const auto num_col = static_cast<int>(grid.front().size());

        auto perimeter = 0;

        for (auto row = 0; row != num_row; ++row) {
            

            
            for (auto col = 0; col != num_col; ++col) {

                if (row == num_row - 1 && grid[row][col] == 1) {
                    perimeter += 1;
                }
                
                if (col == num_col - 1 && grid[row][col] == 1) {
                    perimeter += 1;
                }
                
                const auto cell_left = col == 0 ? 0 : grid[row][col - 1];
                const auto cell_up = row == 0 ? 0 : grid[row - 1][col];

                if (cell_left ^ cell_up) {
                    perimeter += 1;

                    continue;
                }

                if (grid[row][col] ^ cell_left) {

                    perimeter += 2;

                    continue;
                }
            }
        }

        return perimeter;
    }
};
*/