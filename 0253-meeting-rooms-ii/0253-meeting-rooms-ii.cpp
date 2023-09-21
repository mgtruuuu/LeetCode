/*
// Approach 1: Priority Queues
class Solution {
  public:
    int minMeetingRooms(vector<vector<int>>& intervals)
    {
        std::sort(intervals.begin(), intervals.end(),
                  [](const std::vector<int>& a, const std::vector<int>& b) { return (a.front() < b.front()); });

        std::priority_queue<int, std::vector<int>, std::greater<int>> ends;
        auto len_ends = 0;
        for (const auto& interval : intervals) {

            while (ends.empty() == false && ends.top() <= interval.front()) {
                ends.pop();
            }

            ends.push(interval.back());

            if (len_ends < static_cast<int>(ends.size())) {
                len_ends = static_cast<int>(ends.size());
            }
        }

        return len_ends;
    }
};
*/


///*
// Approach 2: Chronological Ordering
class Solution {
  public:
    int minMeetingRooms(vector<vector<int>>& intervals)
    {
        std::vector<int> interval_starts;
        interval_starts.reserve(intervals.size());
        std::vector<int> interval_ends;
        interval_ends.reserve(intervals.size());

        for (const auto& interval : intervals) {
            interval_starts.push_back(interval.front());
            interval_ends.push_back(interval.back());
        }

        std::sort(interval_starts.begin(), interval_starts.end());
        std::sort(interval_ends.begin(), interval_ends.end());

        auto count = 0;
        auto p_start = interval_starts.begin();
        auto p_end = interval_ends.begin();

        while (p_start != interval_starts.end()) {

            if (*p_start >= *p_end) {
                ++p_end;
                --count;
            }

            ++p_start;
            ++count;
        }

        return count;
    }
};
//*/