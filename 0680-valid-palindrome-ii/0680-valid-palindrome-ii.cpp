class Solution {
  private:
    bool checkPalindrome(const std::string& s, int idx_left, int idx_right)
    {
        while (idx_left < idx_right) {
            
            if (s[idx_left++] != s[idx_right--]) {
                return false;
            }
        }

        return true;
    }

  public:
    bool validPalindrome(string s)
    {
        auto idx_left = 0;
        auto idx_right = static_cast<int>(s.size()) - 1;

        while (idx_left < idx_right && s[idx_left] == s[idx_right]) {
            ++idx_left;
            --idx_right;
        }

        return checkPalindrome(s, idx_left + 1, idx_right) || checkPalindrome(s, idx_left, idx_right - 1);
    }
};