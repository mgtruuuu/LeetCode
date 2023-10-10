class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        std::sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> res;
        res.reserve(intervals.size());

        auto prev_start = intervals[0].front();
        auto prev_end = intervals[0].back();

        for (auto idx = std::size_t(1); idx != intervals.size(); ++idx) {

            if (prev_end < intervals[idx].front()) {

                res.push_back({ prev_start, prev_end });

                prev_start = intervals[idx].front();
                prev_end = intervals[idx].back();
            }
            else if (prev_end < intervals[idx].back()) {
                prev_end = intervals[idx].back();
            }
        }

        res.push_back({ prev_start, prev_end });

        return res;
    }
};