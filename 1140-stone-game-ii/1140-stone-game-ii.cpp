///*
// Approach 1: Memoization
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
//*/


/*
class Solution {
  public:
    int stoneGameII(vector<int>& piles)
    {
        const auto len_piles = piles.size();
        constexpr auto zero = std::size_t(0);
        constexpr auto one = std::size_t(1);

        std::array<std::vector<std::vector<int>>, 2> scores;
        for (auto& player : scores) {

            player.resize(len_piles);

            for (auto j = zero; j != player.size(); ++j) {
                player[j].resize(len_piles - j, 0);
            }
        }

        auto rc = len_piles - 1;
        {
            auto sum_piles = 0;
            for (auto c = zero; c != len_piles; ++c) {

                const auto r = rc - c;

                sum_piles += piles[len_piles - c - one];
                scores[0][r][c] = sum_piles;
                scores[1][r][c] = 0;
            }
        }

        for (; rc-- != 0;) {
            for (auto c = zero; c <= rc; ++c) {

                const auto r = rc - c;

                auto value_max = std::numeric_limits<int>::min();
                auto value_min = std::numeric_limits<int>::max();
                auto sum_max = 0;
                {
                    auto x = one;
                    for (; x <= std::size_t(2) * (c + one) && x < len_piles - r; ++x) {

                        sum_max += piles[r + x - one];

                        const auto c_next = std::min(std::max(c + one, x), len_piles) - one;

                        if (value_max < sum_max + scores[1][r + x][std::min(c_next, len_piles - r - x - 1)]) {
                            value_max = sum_max + scores[1][r + x][std::min(c_next, len_piles - r - x - 1)];
                        }

                        if (value_min > scores[0][r + x][std::min(c_next, len_piles - r - x - 1)]) {
                            value_min = scores[0][r + x][std::min(c_next, len_piles - r - x - 1)];
                        }
                    }

                    if (x <= std::size_t(2) * (c + one)) {

                        sum_max += piles[r + x - one];

                        if (value_max < sum_max) {
                            value_max = sum_max;
                        }
                        value_min = 0;
                    }
                }

                scores[0][r][c] = value_max;
                scores[1][r][c] = value_min;
            }
        }

        return scores[0][0][0];
    }
};
*/