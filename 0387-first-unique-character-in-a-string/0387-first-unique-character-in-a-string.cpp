class Solution {
  public:
    int firstUniqChar(string s)
    {
        constexpr auto len_alphabet = ('z' - 'a') + 1;

        int counts[len_alphabet] = { 0 };

        for (auto idx = s.size(); idx-- != 0;) {

            counts[s[idx] - 'a'] += 1;
        }

        for (auto res = 0; res != static_cast<int>(s.size()); ++res) {

            if (counts[s[res] - 'a'] == 1) {
                return res;
            }
        }

        return -1;
    }
};