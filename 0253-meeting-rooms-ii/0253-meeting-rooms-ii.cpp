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