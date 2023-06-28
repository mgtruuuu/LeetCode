class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a.front() != b.front() ? (a.front() < b.front()) : (a.back() < b.back());
        });

        std::vector<std::vector<int>> res;
        auto prev_left = intervals.front().front();
        auto prev_right = intervals.front().back();
        for (auto idx = std::size_t(1); idx != intervals.size(); ++idx) {

            if (prev_right < intervals[idx].front()) {
                res.push_back(std::vector<int>{ prev_left, prev_right });
                prev_left = intervals[idx].front();
                prev_right = intervals[idx].back();
            }
            else if (prev_right < intervals[idx].back()) {
                prev_right = intervals[idx].back();
            }
        }

        res.push_back(std::vector<int>{ prev_left, prev_right });

        return res;
    }
};