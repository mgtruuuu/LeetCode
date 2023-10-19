/*
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
*/


class Solution {
  public:
    int reverse(int x)
    {
        if (x == 0) {
            return 0;
        }

        std::stack<int> s;
        while (x != 0) {
            const auto quotient = x / 10;
            s.push(x - 10 * quotient);
            x = quotient;
        }

        auto res = 0;
        const auto len_q = static_cast<int>(s.size());

        if (len_q < 10) {
            for (auto i = 0; i != len_q; ++i) {

                auto mul = s.top();
                for (auto j = 0; j != i; ++j) {
                    mul *= 10;
                }

                res += mul;
                s.pop();
            }
        }
        else {

            for (auto i = 0; i != len_q - 1; ++i) {

                auto mul = s.top();
                for (auto j = 0; j != i; ++j) {
                    mul *= 10;
                }

                res += mul;
                s.pop();
            }

            {
                auto mul = s.top();

                if (mul > 2 || mul < -2) {
                    return 0;
                }

                for (auto j = 0; j != len_q - 1; ++j) {
                    mul *= 10;
                }

                if ((res > 0 && INT_MAX - res < mul) || (res < 0 && INT_MIN - res > mul)) {
                    return 0;
                }

                res += mul;
                s.pop();
            }
        }

        return res;
    }
};