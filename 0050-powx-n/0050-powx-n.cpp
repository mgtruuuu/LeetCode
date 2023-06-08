class Solution {
  public:
    double myPow(double x, int n)
    {
        if (n == 0 || x == 1.0) {
            return 1.0;
        }
        else if (n > 0) {
            return myPowHelper(x, static_cast<uint32_t>(n));
        }
        else if (n != -2147483648) {
            return 1.0 / myPowHelper(x, static_cast<uint32_t>(-n));
        }
        else {
            return 1.0 / myPowHelper(x, static_cast<uint32_t>(2147483648));
        }
    }

    double myPowHelper(double x, uint32_t n)
    {
        auto res = 1.0;

        while (n != 0) {
            if (n & 1) {
                res *= x;
            }

            n >>= 1;
            x *= x;
        }

        return res;
    }
};