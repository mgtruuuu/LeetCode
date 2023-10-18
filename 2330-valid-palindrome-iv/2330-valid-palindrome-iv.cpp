class Solution {
  public:
    bool makePalindrome(string s)
    {
        auto idx_left = 0;
        auto idx_right = static_cast<int>(s.size()) - 1;

        auto count_left = 2;
        while (count_left-- != 0) {

            while (idx_left < idx_right && s[idx_left++] == s[idx_right--]) {
            }
        }

        if (idx_left >= idx_right) {
            return true;
        }
        
        while (idx_left < idx_right) {

            if (s[idx_left++] != s[idx_right--]) {
                return false;
            }
        }
        
        return true;
    }
};