///*
// Approach 1: Priority Queues
class Solution {
  public:
    int minMeetingRooms(vector<vector<int>>& intervals)
    {
        std::sort(intervals.begin(), intervals.end());

        auto res = std::size_t(0); // the minimum number of conference rooms required
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (const auto& interval : intervals) {

            while (pq.empty() == false && pq.top() <= interval.front()) {
                pq.pop();
            }

            pq.push(interval.back());
            if (res < pq.size()) {
                res = pq.size();
            }
        }

        return res;
    }
};
//*/


/*
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
*/