class Solution {
  public:
    bool isIsomorphic(string s, string t)
    {
        std::unordered_map<char, char> hash_s2t;
        std::unordered_set<char> check_duplication;

        for (auto idx = std::size_t(0); idx != s.size(); ++idx) {
            if (hash_s2t.count(s[idx]) == 0) {

                if (check_duplication.count(t[idx]) == 0) {
                    check_duplication.insert(t[idx]);
                    hash_s2t[s[idx]] = t[idx];
                }
                else {
                    return false;
                }
            }
            else if (hash_s2t[s[idx]] != t[idx]) {
                return false;
            }
        }

        return true;
    }
};