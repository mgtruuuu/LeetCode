class Solution {
  public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            if (a.back() != b.back()) {
                return a.back() < b.back();
            }
            else {
                return a.front() < b.front();
            }
        });

        std::vector<int> ends;
        ends.push_back(points.front().back());
        for (auto idx = std::size_t(1); idx != points.size(); ++idx) {

            if (ends.back() == points[idx].back() || points[idx].front() <= ends.back()) {
                continue;
            }

            ends.push_back(points[idx].back());
        }

        return static_cast<int>(ends.size());
    }
};