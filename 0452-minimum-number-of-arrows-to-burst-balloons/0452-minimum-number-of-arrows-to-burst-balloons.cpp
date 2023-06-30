class Solution {
  public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a.back() < b.back();
        });

        auto prev_back = points.front().back();
        auto count = 1;
        for (auto idx = std::size_t(1); idx != points.size(); ++idx) {

            if (points[idx].front() <= prev_back) {
                continue;
            }

            prev_back = points[idx].back();
            ++count;
        }

        return count;
    }
};