class Solution {
  public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        if (intervals.empty() == true) {
            return { newInterval };
        }

        std::vector<std::vector<int>> res;
        res.reserve(intervals.size() + 1);

        auto idx_new_front = std::size_t(0);
        while (idx_new_front != intervals.size()) {

            if (newInterval.front() <= intervals[idx_new_front].back()) {
                break;
            }
            else {

                res.push_back(intervals[idx_new_front]);

                ++idx_new_front;
            }
        }

        if (idx_new_front == intervals.size()) {
            res.push_back(newInterval);
            res.shrink_to_fit();

            return res;
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
            res.push_back(newInterval);
            for (const auto& interval : intervals) {
                res.push_back(interval);
            }
            return res;
        }

        --idx_new_back;

        res.push_back(std::vector<int>{ std::min(newInterval.front(), intervals[idx_new_front].front()),
                                        std::max(newInterval.back(), intervals[idx_new_back].back()) });
        for (auto idx = idx_new_back + 1; idx != intervals.size(); ++idx) {
            res.push_back(intervals[idx]);
        }
        res.shrink_to_fit();

        return res;
    }
};