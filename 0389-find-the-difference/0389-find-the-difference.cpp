class Solution {
  public:
    char findTheDifference(string s, string t)
    {
        if (s.size() < t.size()) {
            auto temp = std::move(s);
            s = std::move(t);
            t = std::move(temp);
        }

        std::unordered_map<char, int> char2count;
        for (const auto& ch : t) {
            ++char2count[ch];
        }

        for (const auto& ch : s) {

            if (--char2count[ch] == -1) {
                return ch;
            }
        }

        return '0'; // must not be returned
    }
};