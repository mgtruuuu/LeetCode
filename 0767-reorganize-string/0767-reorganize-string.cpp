/*
// Approach 1: Counting and Priority Queue
class Solution {
  private:
    using MyType = std::pair<char, int>;
    struct MyCmp {
        bool operator()(const MyType& lhs, const MyType& rhs) const
        {
            return lhs.second < rhs.second;
        }
    };

  public:
    string reorganizeString(string s)
    {
        constexpr auto len_alphabets = 'z' - 'a' + 1;

        int counts[len_alphabets] = {
            0,
        };
        for (const auto ch : s) {
            ++counts[ch - 'a'];
        }

        std::priority_queue<MyType, std::vector<MyType>, MyCmp> pq;
        for (auto idx = 0; idx != len_alphabets; ++idx) {

            if (counts[idx] != 0) {
                pq.emplace('a' + idx, counts[idx]);
            }
        }

        const auto len_s = static_cast<int>(s.size());
        if (pq.top().second > (len_s + 1) / 2) {
            return "";
        }

        std::string reorganized;
        reorganized.reserve(len_s);

        while (pq.empty() == false) {

            auto temp1 = pq.top();
            pq.pop();

            if (reorganized.empty() == true || reorganized.back() != temp1.first) {

                reorganized.push_back(temp1.first);

                if (--temp1.second > 0) {
                    pq.push(temp1);
                }
            }
            else if (pq.empty() == true) {
                return "";
            }
            else {

                auto temp2 = pq.top();
                pq.pop();

                reorganized.push_back(temp2.first);
                reorganized.push_back(temp1.first);

                if (--temp1.second > 0) {
                    pq.push(temp1);
                }

                if (--temp2.second > 0) {
                    pq.push(temp2);
                }
            }
        }

        return reorganized;
    }
};
*/


///*
// Approach 2: Counting and Odd/Even
class Solution {
  public:
    string reorganizeString(string s)
    {
        constexpr auto len_alphabets = 'z' - 'a' + 1;

        int counts[len_alphabets] = {
            0,
        };
        for (const auto ch : s) {
            ++counts[ch - 'a'];
        }

        auto idx_max = 0;
        auto count_max = counts[0];
        for (auto idx = 0; idx != len_alphabets; ++idx) {

            if (counts[idx] > count_max) {
                idx_max = idx;
                count_max = counts[idx];
            }
        }

        const auto len_s = static_cast<int>(s.size());
        if (count_max > (len_s + 1) / 2) {
            return "";
        }

        std::string reorganized = s;

        auto idx_reorganized = 0;
        while (counts[idx_max]-- != 0) {

            reorganized[idx_reorganized] = 'a' + idx_max;
            idx_reorganized += 2;
        }
        ++counts[idx_max];

        for (auto idx = 0; idx != len_alphabets; ++idx) {

            while (counts[idx]-- != 0) {

                if (idx_reorganized >= len_s) {
                    idx_reorganized = 1;
                }

                reorganized[idx_reorganized] = 'a' + idx;
                idx_reorganized += 2;
            }
        }

        return reorganized;
    }
};
//*/


