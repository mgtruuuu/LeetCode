class Solution {
  public:
    void reverseString(vector<char>& s)
    {
        auto len_s = static_cast<int>(s.size());

        for (auto idx = 0; idx != len_s / 2; ++idx) {
            std::swap(s[idx], s[len_s - 1 - idx]);
        }
    }
};