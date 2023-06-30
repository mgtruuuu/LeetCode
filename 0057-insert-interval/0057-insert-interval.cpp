class Solution {
  public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        if (intervals.empty() == true) {
            return { newInterval };
        }

        auto idx_new_front = std::size_t(0);
        while (idx_new_front != intervals.size()) {

            if (newInterval.front() <= intervals[idx_new_front].back()) {
                break;
            }
            else {
                ++idx_new_front;
            }
        }

        if (idx_new_front == intervals.size()) {
            std::vector<std::vector<int>> temp = intervals;
            temp.push_back(newInterval);
            return temp;
        }

        auto idx_new_back = idx_new_front;
        while (idx_new_back != intervals.size()) {
            if (newInterval.back() < intervals[idx_new_back].front()) {
                break;
            }
            else {
                ++idx_new_back;
            }
        }

        if (idx_new_back == 0) {
            std::vector<std::vector<int>> temp;
            temp.reserve(intervals.size() + 1);
            temp.push_back(newInterval);
            for (const auto& interval : intervals) {
                temp.push_back(interval);
            }
            return temp;
        }

        --idx_new_back;

        std::vector<std::vector<int>> res;
        for (auto idx = std::size_t(0); idx != idx_new_front; ++idx) {
            res.push_back(intervals[idx]);
        }
        res.push_back(std::vector<int>{ std::min(newInterval.front(), intervals[idx_new_front].front()),
                                        std::max(newInterval.back(), intervals[idx_new_back].back()) });
        for (auto idx = idx_new_back + 1; idx != intervals.size(); ++idx) {
            res.push_back(intervals[idx]);
        }
        return res;
    }
};