class Solution {
  public:
    string toLowerCase(string s)
    {
        for (auto& ch : s) {
            if ('A' <= ch && ch <= 'Z') {
                ch += ('a' - 'A');
            }
        }

        return s;
    }
};