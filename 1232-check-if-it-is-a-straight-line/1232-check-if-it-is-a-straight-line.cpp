class Solution {
  public:
    bool checkStraightLine(vector<vector<int>>& coordinates)
    {
        const auto x_init = coordinates[0].front();
        const auto y_init = coordinates[0].back();
        
        const auto delta_x_init = coordinates[1].front() - x_init;
        const auto delta_y_init = coordinates[1].back() - y_init;

        for (auto idx = std::size_t(2); idx != coordinates.size(); ++idx) {

            const auto delta_x = coordinates[idx].front() - x_init;
            const auto delta_y = coordinates[idx].back() - y_init;

            if (delta_x_init * delta_y != delta_y_init * delta_x) {
                return false;
            }
        }

        return true;
    }
};