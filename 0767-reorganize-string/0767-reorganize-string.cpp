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
        const auto mod = len_s & 1 ? len_s : len_s - 1;

        std::string reorganized = s;
        auto idx = 0;

        {
            const auto alphabet = pq.top().first;
            auto count = pq.top().second;
            pq.pop();

            if (count > (len_s + 1) / 2) {
                return "";
            }

            while (count-- != 0) {

                reorganized[idx % mod] = alphabet;
                idx += 2;
            }
        }

        while (pq.size() > 1) {

            const auto alphabet = pq.top().first;
            auto count = pq.top().second;
            pq.pop();

            while (count-- != 0) {

                reorganized[idx % mod] = alphabet;
                idx += 2;
            }
        }

        {
            const auto alphabet = pq.top().first;
            auto count = pq.top().second;
            pq.pop();

            while (count-- > 1) {

                reorganized[idx % mod] = alphabet;
                idx += 2;
            }

            {
                reorganized[idx - mod] = alphabet;
                idx += 2;
            }
        }

        return reorganized;
    }
};