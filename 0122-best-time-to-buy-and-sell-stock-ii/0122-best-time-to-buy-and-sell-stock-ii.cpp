class Solution {
  public:
    int maxProfit(vector<int>& prices)
    {
        auto res = 0;
        for (auto idx = std::size_t(1); idx != prices.size(); ++idx) {
            if (prices[idx] - prices[idx - 1] > 0) {
                res += (prices[idx] - prices[idx - 1]);
            }
        }

        return res;
    }
};