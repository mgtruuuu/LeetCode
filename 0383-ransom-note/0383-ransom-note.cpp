class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine)
    {
        std::unordered_map<char, int> hash_char2count;

        for (const auto& ch : magazine) {

            ++hash_char2count[ch];
        }

        for (const auto& ch : ransomNote) {

            if (hash_char2count.find(ch) != hash_char2count.end() && hash_char2count[ch] > 0) {
                --hash_char2count[ch];
            }
            else {
                return false;
            }
        }

        return true;
    }
};