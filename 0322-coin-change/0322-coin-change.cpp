class Solution {
  public:
    int coinChange(vector<int>& coins, int amount)
    {
        std::vector<int> seq(amount + 1);

        seq[0] = 0;
        for (auto idx = std::size_t(1); idx != seq.size(); ++idx) {
            auto min = std::numeric_limits<int>::max();
            for (const auto& coin : coins) {

                if (idx < coin) {
                    continue;
                }

                if (seq[idx - coin] != -1 && seq[idx - coin] < min) {
                    min = seq[idx - coin];
                }
            }

            if (min == std::numeric_limits<int>::max()) {
                seq[idx] = -1;
            }
            else {
                seq[idx] = min + 1;
            }
        }

        return seq.back();
    }
};