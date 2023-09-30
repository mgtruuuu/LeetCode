class Solution {
  public:
    int stoneGameII(vector<int>& piles)
    {
        const auto len_piles = static_cast<int>(piles.size());

        std::vector dp(2, std::vector<std::vector<int>>(len_piles));
        for (auto& player : dp) {
            for (auto i = 0; i != len_piles; ++i) {
                player[i] = std::vector<int>(len_piles + 1 - i, -1);
            }
        }

        std::function<int(int, int, int)> fcn = [&](int p, int i, int m) -> int {
            
            if (i == len_piles) {
                return 0;
            }
            
            if (i + m > len_piles) {
                m = len_piles - i;
            }
            
            if (dp[p][i][m] != -1) {
                return dp[p][i][m];
            }

            auto res = p == 1 ? std::numeric_limits<int>::max() : -1;
            auto sum = 0;
            for (int x = 1; x <= min(2 * m, len_piles - i); ++x) {

                sum += piles[i + x - 1];
                if (p == 0) {
                    res = std::max(res, sum + fcn(1, i + x, max(m, x)));
                }
                else {
                    res = std::min(res, fcn(0, i + x, max(m, x)));
                }
            }

            return (dp[p][i][m] = res);
        };

        return fcn(0, 0, 1);
    }
};