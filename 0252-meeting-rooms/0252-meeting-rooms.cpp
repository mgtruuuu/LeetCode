class Solution {
  public:
    bool canAttendMeetings(vector<vector<int>>& intervals)
    {
        std::sort(intervals.begin(), intervals.end());

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