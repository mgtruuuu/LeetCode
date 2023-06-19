class Solution {
  public:
    bool isIsomorphic(string s, string t)
    {
        std::unordered_set<char> check_duplication;
        std::unordered_map<char, char> hash_s2t;

        for (auto idx = std::size_t(0); idx != s.size(); ++idx) {
            if (hash_s2t.find(s[idx]) == hash_s2t.end()) {

                if (check_duplication.find(t[idx]) == check_duplication.end()) {
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