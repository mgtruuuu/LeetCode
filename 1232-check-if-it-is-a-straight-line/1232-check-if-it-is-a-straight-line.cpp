class Solution {
  public:
    bool checkStraightLine(vector<vector<int>>& coordinates)
    {
        const auto delta_x_init = coordinates[1].front() - coordinates[0].front();
        const auto delta_y_init = coordinates[1].back() - coordinates[0].back();

        for (auto idx = std::size_t(1); idx != coordinates.size() - 1; ++idx) {

            const auto delta_x = coordinates[idx + 1].front() - coordinates[idx].front();
            const auto delta_y = coordinates[idx + 1].back() - coordinates[idx].back();

            if (delta_x_init * delta_y != delta_y_init * delta_x) {
                return false;
            }
        }

        return true;
    }
};