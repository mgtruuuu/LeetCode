class Solution {
  public:
    vector<int> partitionLabels(string s)
    {
        std::unordered_map<char, std::pair<int, int>> char2interval;

        for (auto idx = 0; idx != static_cast<int>(s.size()); ++idx) {

            if (char2interval.find(s[idx]) == char2interval.end()) {
                char2interval[s[idx]] = std::make_pair(idx, idx);
            }
            else {
                char2interval[s[idx]].second = idx;
            }
        }

        std::vector<std::pair<int, int>> intervals;
        intervals.reserve(s.size());
        for (const auto& [k, v] : char2interval) {
            intervals.push_back(v);
        }
        intervals.shrink_to_fit();

        std::sort(intervals.begin(), intervals.end());

        std::vector<int> res;
        res.reserve(intervals.size());

        auto subtract = 0;
        auto prev_start = intervals[0].first;
        auto prev_end = intervals[0].second;

        for (auto idx = std::size_t(1); idx != intervals.size(); ++idx) {

            if (prev_end < intervals[idx].first) {

                res.push_back(prev_end + 1 - subtract);
                subtract = prev_end + 1;

                prev_start = intervals[idx].first;
                prev_end = intervals[idx].second;
            }
            else if (prev_end < intervals[idx].second) {
                prev_end = intervals[idx].second;
            }
        }
        
        res.push_back(prev_end + 1 - subtract);

        return res;
    }
};