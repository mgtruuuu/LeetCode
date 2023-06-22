class Solution {
  public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size()) {
            return false;
        }
        
        auto alphabet_table = std::vector<int>(static_cast<int>('z') - static_cast<int>('a') + 1, 0);

        for (const auto& ch : s) {
            ++alphabet_table[static_cast<int>(ch) - static_cast<int>('a')];
        }

        for (const auto& ch : t) {
            if (--alphabet_table[static_cast<int>(ch) - static_cast<int>('a')] == -1) {
                return false;
            }
        }

        return true;
    }
};