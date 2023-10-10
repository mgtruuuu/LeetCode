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