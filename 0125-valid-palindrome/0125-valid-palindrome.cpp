class Solution {
  public:
    bool isPalindrome(string s)
    {
        auto ptr_left = s.begin();
        auto ptr_right = s.end() - 1;
        while (ptr_left <= ptr_right) {
            if (isalnum(*ptr_left) == false) {
                ++ptr_left;
                continue;
            }

            if (isalnum(*ptr_right) == false) {
                --ptr_right;
                continue;
            }

            if (tolower(*ptr_left) != tolower(*ptr_right)) {
                return false;
            }

            ++ptr_left;
            --ptr_right;
        }

        return true;
    }
};