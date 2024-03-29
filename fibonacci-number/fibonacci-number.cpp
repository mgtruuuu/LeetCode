class Solution {
  public:
    int fib(int n)
    {
        if (n <= 1) {
            return n;
        }

        auto current = 0;
        auto prev1 = 1;
        auto prev2 = 0;

        for (int i = 2; i <= n; ++i) {

            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }

        return current;
    }
};