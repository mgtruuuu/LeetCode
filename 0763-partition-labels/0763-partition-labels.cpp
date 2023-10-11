// Approach 0: Brute force


/*
// Approach 1: Greedy
class Solution {
  public:
    vector<int> partitionLabels(string s)
    {
        constexpr auto len_alphabets = static_cast<int>('a' - 'A');
        const auto len_s = static_cast<int>(s.size());

        std::array<int, len_alphabets> char2index{
            0,
        };
        for (auto idx = 0; idx != len_s; ++idx) {
            char2index[s[idx] - 'a'] = idx;
        }

        std::vector<int> res;
        auto anchor = 0;
        auto idx_rhs = 0;
        for (auto idx_lhs = 0; idx_lhs != len_s; ++idx_lhs) {

            if (idx_rhs < char2index[s[idx_lhs] - 'a']) {
                idx_rhs = char2index[s[idx_lhs] - 'a'];
            }

            if (idx_lhs == idx_rhs) {
                res.push_back((++idx_rhs) - anchor);
                anchor += res.back();
            }
        }

        return res;
    }
};
*/


///*
// Approach 2: Merge Intervals
class Solution {
  private:
    int getIndex(const std::string& s, const int idx)
    {
        return (s[idx] - 'a');
    }

  public:
    vector<int> partitionLabels(string s)
    {
        constexpr auto len_alphabets = static_cast<int>('a' - 'A');

        std::array<std::pair<int, int>, len_alphabets> char2interval;
        char2interval.fill(std::make_pair(-1, 0));
        for (auto idx = 0; idx != static_cast<int>(s.size()); ++idx) {

            const auto my_idx = getIndex(s, idx);
            
            if (char2interval[getIndex(s, idx)].first == -1) {
                char2interval[getIndex(s, idx)].first = idx;
            }
            
            char2interval[getIndex(s, idx)].second = idx;
        }

        std::sort(char2interval.begin(), char2interval.end());

        std::vector<int> res;

        auto idx = 0;
        while (char2interval[idx].first != -1) {
            ++idx;
        }

        auto subtract = 0;
        auto prev_start = char2interval[idx].first;
        auto prev_end = char2interval[idx].second;

        for (++idx; idx != len_alphabets; ++idx) {

            if (prev_end < char2interval[idx].first) {

                res.push_back(prev_end + 1 - subtract);
                subtract = prev_end + 1;

                prev_start = char2interval[idx].first;
                prev_end = char2interval[idx].second;
            }
            else if (prev_end < char2interval[idx].second) {
                prev_end = char2interval[idx].second;
            }
        }

        res.push_back(prev_end + 1 - subtract);
        return res;
    }
};
//*/