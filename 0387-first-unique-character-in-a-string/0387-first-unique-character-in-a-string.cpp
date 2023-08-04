class Solution {
  public:
    int firstUniqChar(string s)
    {
        constexpr auto len_alphabet = ('z' - 'a') + 1;

        int counts[len_alphabet] = { 0 };

        std::stack<int> alphabets;
        for (auto idx = s.size(); idx-- != 0;) {
                        
            counts[s[idx] - 'a'] += 1;
            alphabets.push(s[idx]);
        }

        auto res = 0;
        while (alphabets.empty() == false) {

            if (counts[alphabets.top() - 'a'] == 1) {
                return res;
            }

            ++res;
            alphabets.pop();
        }

        return -1;
    }
};