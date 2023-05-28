#include <queue>

class Solution {
  public:
    int fib(int n)
    {
        if (n == 0) {
            return 0;
        }
        else if (n == 1) {
            return 1;
        }

        std::queue<int> fibonacci_seq;
        fibonacci_seq.push(0);
        fibonacci_seq.push(1);

        for (auto idx = 2; idx < n + 1; ++idx) {

            const auto front = fibonacci_seq.front();

            fibonacci_seq.pop();
            fibonacci_seq.push(front + fibonacci_seq.front());
        }

        return fibonacci_seq.back();
    }

    // int fib(int n)
    // {

    //     if (n == 0) {
    //         return 0;
    //     }
    //     else if (n == 1) {
    //         return 1;
    //     }

    //     std::vector<int> fibonacci_seq(n + 1, 0);
    //     fibonacci_seq[0] = 0;
    //     fibonacci_seq[1] = 1;

    //     for (auto idx = 2; idx < n + 1; ++idx) {
    //         fibonacci_seq[idx] = fibonacci_seq[idx - 1] + fibonacci_seq[idx - 2];
    //     }

    //     return fibonacci_seq[n];
    // }
};