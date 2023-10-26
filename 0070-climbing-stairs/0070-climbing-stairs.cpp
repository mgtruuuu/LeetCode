/*
// Approach 1: Dynamic Programming (Fibonacci Number)
class Solution {
public:
    int climbStairs(int n)
    {
        if (n == 1) {
            return 1;
        }
        else if (n == 2) {
            return 2;
        }

        std::queue<int> fibonacci_seq;
        fibonacci_seq.push(1);
        fibonacci_seq.push(2);

        for (auto idx = 3; idx <= n; ++idx) {

            const auto front = fibonacci_seq.front();

            fibonacci_seq.pop();
            fibonacci_seq.push(front + fibonacci_seq.front());
        }

        return fibonacci_seq.back();
    }
};
*/


///*
// Approach 2: Binets Method
class Solution {
  private:
    std::vector<std::vector<int>> pow(const std::vector<std::vector<int>>& a, int n)
    {
        auto a_copy = a;

        std::vector<std::vector<int>> ret = { { 1, 0 }, { 0, 1 } };

        if (n & 1) {
            ret = multiply(ret, a_copy);
        }
        n >>= 1;

        while (n != 0) {

            a_copy = multiply(a_copy, a_copy);

            if (n & 1) {
                ret = multiply(ret, a_copy);
            }
            n >>= 1;
        }

        return ret;
    }

    std::vector<std::vector<int>> multiply(const std::vector<std::vector<int>>& a,
                                           const std::vector<std::vector<int>>& b)
    {
        std::vector<std::vector<int>> c(2, std::vector<int>(2, 0));
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return c;
    }

  public:
    int climbStairs(int n)
    {
        std::vector<std::vector<int>> q = { { 1, 1 }, { 1, 0 } };
        std::vector<std::vector<int>> res = pow(q, n);
        return res[0][0];
    }
};
//*/


/*
// Approach 3: Fibonacci Formula
class Solution {
  public:
    int climbStairs(int n)
    {
        const auto sqrt5 = sqrt(5);
        const auto phi = (1.0 + sqrt5) * 0.5;
        const auto psi = (1.0 - sqrt5) * 0.5;

        return static_cast<int>((pow(phi, n + 1) - pow(psi, n + 1)) / sqrt5);
    }
};
*/