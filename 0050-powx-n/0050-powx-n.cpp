/*
// Approach 1: Binary Exponentiation (Recursive)
class Solution {
  private:
    double myPowHelper(double x, int n)
    {
        if (n == 0) {
            return 1.0;
        }

        if (n & 1) {
            return x * myPowHelper(x * x, n >> 1);
        }
        else {
            return myPowHelper(x * x, n >> 1);
        }
    }

  public:
    double myPow(double x, int n)
    {
        if (x == 0.0 || x == 1.0) {
            return x;
        }

        if (n == 0) {
            return 1.0;
        }

        if (n == INT_MIN) {

            x = x * x;
            n >>= 1;  // the same as n /= 2;
        }

        if (n < 0) {
            x = 1.0 / x;
            n = (n ^ 0xFFFFFFFF) + 1; // the same as -n;
        }

        return myPowHelper(x, n);
    }
};
*/




// Approach 2: Binary Exponentiation (Iterative)
class Solution {
  private:
    double myPowHelper(double x, int n)
    {
        if (n == 0) {
            return 1.0;
        }

        if (n & 1) {
            return x * myPowHelper(x * x, n >> 1);
        }
        else {
            return myPowHelper(x * x, n >> 1);
        }
    }

  public:
    double myPow(double x, int n)
    {
        if (x == 0.0 || x == 1.0) {
            return x;
        }

        if (n == 0) {
            return 1.0;
        }

        if (n == INT_MIN) {

            x = x * x;
            n >>= 1;  // the same as n /= 2;
        }

        if (n < 0) {
            x = 1.0 / x;
            n = (n ^ 0xFFFFFFFF) + 1; // the same as -n;
        }

        auto res = 1.0;

        while (n != 0) {

            if (n & 1) {
                res *= x;
            }

            x = x * x;
            n >>= 1;
        }

        return res;
    }
};