class Solution {
  public:
    bool isPalindrome(string s)
    {
        auto ptr_left = s.begin();
        auto ptr_right = s.end() - 1;
        while (ptr_left < ptr_right) {

            while (ptr_left < ptr_right && isalnum(*ptr_left) == false) {
                ++ptr_left;
            }

            while (ptr_left < ptr_right && isalnum(*ptr_right) == false) {
                --ptr_right;
            }

            if (tolower(*ptr_left++) != tolower(*ptr_right--)) {
                return false;
            }
        }

        return true;
    }
};