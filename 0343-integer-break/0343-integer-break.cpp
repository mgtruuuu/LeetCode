class Solution {
  public:
    int integerBreak(int n)
    {
        if (n <= 3) {
            return n - 1;
        }

        std::vector<int> memo(n + 1, 0);
        memo[1] = 1;
        memo[2] = 2;
        memo[3] = 3;

        for (auto num = 4; num <= n; ++num) {

            for (auto i = 1; i <= num - 1; ++i) {

                if (memo[num] < i * memo[num - i]) {
                    memo[num] = i * memo[num - i];
                }
            }

            std::cout << "memo[" << num << "] : " << memo[num] << std::endl;
        }

        return memo[n];
    }
};
