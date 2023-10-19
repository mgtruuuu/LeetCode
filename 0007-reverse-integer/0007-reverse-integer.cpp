constexpr auto int_max_last = 7;
constexpr auto int_min_last = -8;

class Solution {
  public:
    int reverse(int x)
    {
        auto res = 0;
        while (x != 0) {
            auto pop = x % 10;
            x /= 10;

            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && pop > int_max_last)) {
                return 0;
            }

            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && pop < int_min_last)) {
                return 0;
            }

            res = res * 10 + pop;
        }

        return res;
    }
};