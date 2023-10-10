class Solution {
  public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& lhs, const std::vector<int>& rhs) {
            return (lhs.back() == rhs.back() ? lhs.front() < rhs.front() : lhs.back() < rhs.back());
        });

        auto num_to_delete = 0;
        auto interval_end = -50001;
        for (const auto& interval : intervals) {

            if (interval_end <= interval.front()) {
                interval_end = interval.back();
            }
            else {
                ++num_to_delete;
            }
        }

        return num_to_delete;
    }
};