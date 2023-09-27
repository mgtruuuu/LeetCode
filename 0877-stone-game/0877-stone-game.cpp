


///*
// Approach 1: Dynamic Programming
class Solution {
  public:
    bool stoneGame(vector<int>& piles)
    {
        const auto len_piles = piles.size();

        std::vector<std::vector<int>> scores(len_piles, std::vector<int>(len_piles));

        // case : diff == 0
        auto diff = std::size_t(0);
        for (auto r = std::size_t(0), c = r + diff; c != len_piles; ++r, ++c) {
            scores[r][c] = -piles[r];
        }
        ++diff;

        for (; diff != len_piles; ++diff) {
            for (auto r = std::size_t(0), c = r + diff; c != len_piles; ++r, ++c) {

                // diff is odd
                if (diff & 1) {
                    scores[r][c] = std::max(piles[r] + scores[r + 1][c], piles[c] + scores[r][c - 1]);
                }
                else {
                    scores[r][c] = std::min(-piles[r] + scores[r + 1][c], -piles[c] + scores[r][c - 1]);
                }
            }
        }

        return scores[0][len_piles - 1] > 0;
    }
};
//*/

/*
// Approach 2: Mathematical
class Solution {
  public:
    bool stoneGame(vector<int>& piles)
    {
        return true;
    }
};
*/

