class Solution {
  public:
    string reorganizeString(string s)
    {
        constexpr auto len = 'z' - 'a' + 1;

        int counts[len] = {
            0,
        };
        for (const auto c : s) {
            ++counts[c - 'a'];
        }

        // Max heap ordered by character counts
        priority_queue<vector<int>> pq;
        for (auto i = 0; i != 26; ++i) {
            if (counts[i] > 0) {
                pq.push(vector<int>{ counts[i], i + 'a' });
            }
        }

        std::string result;
        while (pq.empty() == false) {

            auto first = pq.top();
            pq.pop();
            if (result.empty() == true || first[1] != result.back()) {

                result += char(first[1]);

                if (--first[0] > 0) {
                    pq.push(first);
                }
            }
            else {

                if (pq.empty()) {
                    return "";
                }

                auto second = pq.top();
                pq.pop();

                result += char(second[1]);

                if (--second[0] > 0) {
                    pq.push(second);
                }
                pq.push(first);
            }
        }

        return result;
    }
};