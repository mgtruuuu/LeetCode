class Solution {
  public:
    int rangeBitwiseAnd(int left, int right)
    {
        if (left == 0 || left == right) {
            return left;
        }

        std::bitset<32> left_bit{ static_cast<unsigned long long>(left) };
        std::bitset<32> right_bit{ static_cast<unsigned long long>(right) };

        auto left_exponent = getExponent(left);
        auto right_exponent = getExponent(right);

        if (left_exponent != right_exponent) {
            return 0;
        }

        auto res = getPower(2, left_exponent);
        auto idx = static_cast<std::size_t>(left_exponent + 1);

        for (std::size_t idx = left_exponent; idx-- != 0;) {
            if (left_bit.test(idx) == true) {
                res += getPower(2, idx);
                continue;
            }

            if (right_bit.test(idx) == true) {
                break;
            }
        }

        return res;
    }
    
    int getExponent(int num, const int base = 2)
    {
        auto exponent = -1;

        while (num != 0) {
            num /= base;

            ++exponent;
        }

        return exponent;
    }

    int getPower(int base, const int exp)
    {
        auto res = 1;

        for (auto i = 0; i != exp; ++i) {
            res *= base;
        }

        return res;
    }
};