class Solution {
  private:
    bool checkPalindrome(const std::string& s, int idx_left, int idx_right, int count_left)
    {
        if (count_left < 0) {
            return false;
        }

        while (idx_left < idx_right) {

            if (s[idx_left] != s[idx_right]) {
                return checkPalindrome(s, idx_left + 1, idx_right - 1, count_left - 1);
            }

            ++idx_left;
            --idx_right;
        }

        return true;
    }

  public:
    bool makePalindrome(string s)
    {
        return checkPalindrome(s, 0, static_cast<int>(s.size()) - 1, 2);
    }
};