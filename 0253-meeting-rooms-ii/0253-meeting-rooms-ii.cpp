class Solution {
  public:
    int minMeetingRooms(vector<vector<int>>& intervals)
    {
        std::sort(intervals.begin(), intervals.end());
        
        std::priority_queue<int, std::vector<int>, std::greater<int>> ends;
        auto count = 0;
        auto max = count;

        for (const auto& interval : intervals) {

            if (ends.empty() == true || interval.front() < ends.top()) {
                count += 1;
                if (max < count) {
                    max = count;
                }
            }
            else {
                ends.pop();
            }

            ends.push(interval.back());
        }

        return max;
    }
};