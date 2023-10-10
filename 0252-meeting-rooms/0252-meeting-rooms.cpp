//*/
class Solution {
  public:
    bool canAttendMeetings(vector<vector<int>>& intervals)
    {
        std::sort(intervals.begin(), intervals.end(),
                  [](const std::vector<int>& lhs, const std::vector<int>& rhs) { return lhs.back() < rhs.back(); });

        auto end_right = 0;
        for (const auto& interval : intervals) {

            if (interval.front() < end_right) {
                return false;
            }

            end_right = interval.back();
        }

        return true;
    }
};
//*/


/*
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
*/