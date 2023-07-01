class Solution {
  public:
    bool canAttendMeetings(vector<vector<int>>& intervals)
    {
        std::sort(intervals.begin(), intervals.end(),
                  [](const std::vector<int>& a, const std::vector<int>& b) { return a.front() < b.front(); });

        auto prev = std::numeric_limits<int>::min();
        for (const auto& interval : intervals) {
            if (prev > interval.front()) {
                return false;
            }

            prev = interval.back();
        }

        return true;
    }
};