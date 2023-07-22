class Solution {
  public:
    double myPow(double x, int n)
    {
        // Base case, to stop recursive calls.
        if (n == 0) {
            return 1;
        }

        // Handle case where, n < 0.
        if (n == std::numeric_limits<int>::min()) {
            return 1.0 / myPow(x * x, static_cast<int>(static_cast<uint32_t>(n) >> 1));
        }
        
        if (n < 0) {
            n = static_cast<int>((n ^ 0xFFFFFFFF) + 1);
            x = 1.0 / x;
        }

        // Perform Binary Exponentiation.
        auto result = 1.0;
        while (n != 0) {

            // If 'n' is odd we multiply result with 'x' and reduce 'n' by '1'.
            if (n & 1) {
                result *= x;
                n -= 1;
            }

            // We square 'x' and reduce 'n' by half, x^n => (x^2)^(n/2).
            x *= x;
            n >>= 1;
        }

        return result;
    }
};



// // class Solution {
// //   public:
// //     double myPow(double x, int n)
// //     {
// //         // Base case, to stop recursive calls.
// //         if (n == 0) {
// //             return 1;
// //         }

// //         // Handle case where, n < 0.
// //         if (n == std::numeric_limits<int>::min()) {
// //             return 1.0 / myPow(x * x, static_cast<int>(static_cast<uint32_t>(n) >> 1));
// //         }
// //         else if (n < 0) {
// //             return 1.0 / myPow(x, static_cast<int>((n ^ 0xFFFFFFFF) + 1));
// //         }

// //         // Perform Binary Exponentiation.
// //         // If 'n' is odd we perform Binary Exponentiation on 'n - 1' and multiply result with 'x'.
// //         if (n & 1) {
// //             return x * myPow(x * x, (n - 1) >> 1);
// //         }
// //         // Otherwise we calculate result by performing Binary Exponentiation on 'n'.
// //         else {
// //             return myPow(x * x, n >> 1);
// //         }
// //     }
// // };