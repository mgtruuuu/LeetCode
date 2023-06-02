class Solution {
  public:
    bool isPalindrome(int x)
    {
        if (x < 0) {
            return false;
        }
        else if (x < 10) {
            return true;
        }

        std::vector<int> nums;
        nums.reserve(10);

        auto q = x;
        do {
            q = x / 10;
            const auto r = x - q * 10;
            nums.push_back(r);
            x = q;
        } while (9 < q);
        nums.push_back(q);

        auto p_left = nums.begin();
        auto p_right = nums.end() - 1;

        while (p_left < p_right) {
            if (*p_left != *p_right) {
                return false;
            }

            ++p_left;
            --p_right;
        }

        return true;
    }
};