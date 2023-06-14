class Solution {
  public:
    int lengthOfLastWord(string s)
    {

        auto idx_rhs = s.size() - 1;
        while (s[idx_rhs] == ' ') {

            if (idx_rhs == 0) {
                return 0;
            }

            --idx_rhs;
        }

        auto count = 0;
        for (auto idx_lhs = ++idx_rhs; idx_lhs-- != 0;) {

            if (s[idx_lhs] == ' ') {
                return count;
            }

            ++count;
        }

        return count;
    }
};