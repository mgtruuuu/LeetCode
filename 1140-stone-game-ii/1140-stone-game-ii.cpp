class Solution {
  public:
    int stoneGameII(vector<int>& piles)
    {
        const auto len_piles = piles.size();
        constexpr auto one = std::size_t(1);

        std::array<std::vector<std::vector<int>>, 2> scores;
        for (auto& i : scores) {
            i = std::vector<std::vector<int>>(len_piles + 1, std::vector<int>(len_piles, 0));
        }

        auto rc = len_piles - 1;
        {
            auto sum_piles = 0;
            for (auto c = std::size_t(0); c != len_piles; ++c) {

                const auto r = rc - c;

                sum_piles += piles[len_piles - c - one];
                scores[0][r][c] = sum_piles;
                scores[1][r][c] = 0;
            }
        }

        for (; rc-- != 0;) {
            for (auto c = std::size_t(0); c <= rc; ++c) {

                const auto r = rc - c;

                auto value_max = std::numeric_limits<int>::min();
                auto value_min = std::numeric_limits<int>::max();
                auto sum_max = 0;
                for (auto x = one; x <= std::size_t(2) * (c + one) && x <= len_piles - r; ++x) {

                    sum_max += piles[r + x - one];

                    const auto c_next = std::min(std::max(c + one, x), len_piles) - one;
                    if (value_max < sum_max + scores[1][r + x][std::min(c_next, len_piles - r - x - 1)]) {
                        value_max = sum_max + scores[1][r + x][std::min(c_next, len_piles - r - x - 1)];
                    }

                    if (value_min > scores[0][r + x][std::min(c_next, len_piles - r - x - 1)]) {
                        value_min = scores[0][r + x][std::min(c_next, len_piles - r - x - 1)];
                    }
                }

                scores[0][r][c] = value_max;
                scores[1][r][c] = value_min;
            }
        }

        return scores[0][0][0];
    }
};