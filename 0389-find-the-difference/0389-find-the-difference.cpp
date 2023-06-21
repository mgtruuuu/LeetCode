class Solution {
  public:
    char findTheDifference(string s, string t)
    {
        auto sum = uint8_t(0);
        for (const auto& ch : s) {
            sum ^= static_cast<uint8_t>(ch);
        }
        for (const auto& ch : t) {
            sum ^= static_cast<uint8_t>(ch);
        }

        return static_cast<char>(sum);
    }
};