#include <queue>

class Solution {
public:
    int climbStairs(int n) {

        if (n == 1) {
            return 1;
        }
        else if (n == 2) {
            return 2;
        }

        std::queue<int> fibonacci_seq;
        fibonacci_seq.push(1);
        fibonacci_seq.push(2);

        for (auto idx = 3; idx <= n ; ++idx) {

            const auto front = fibonacci_seq.front();

            fibonacci_seq.pop();
            fibonacci_seq.push(front + fibonacci_seq.front());
        }

        return fibonacci_seq.back();
        
    }
};