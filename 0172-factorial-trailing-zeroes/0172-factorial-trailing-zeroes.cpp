class Solution {
  public:
    int trailingZeroes(int n)
    {
        auto ans = 0;
        auto i = 0;
        for (i = 5; n / i >= 1; i *= 5) {
            ans += (n / i);
        }

        return ans;
    }
};

// // class Solution {
// //   public:
// //     int hasDivisor(int num, const int divisor)
// //     {
// //         auto quotient = num / divisor;
// //         auto remainder = num - quotient * divisor;

// //         auto count = 0;

// //         while (remainder == 0) {
// //             ++count;
// //             num = quotient;
// //             quotient = num / divisor;
// //             remainder = num - quotient * divisor;
// //         }

// //         return count;
// //     }

// //     int trailingZeroes(int n)
// //     {
// //         auto res = 0;
// //         for (auto i = 5; i <= n; i += 5) {
// //             res += hasDivisor(i, 5);
// //         }

// //         return res;
// //     }
// // };