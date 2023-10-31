class Solution {
  public:
    int maxProfit(vector<int>& prices)
    {
        auto min_price = std::numeric_limits<int>::max();
        auto max_profit = 0;
        for (auto idx = std::size_t(0); idx != prices.size(); ++idx) {

            if (prices[idx] < min_price) {
                min_price = prices[idx];

                continue;
            }

            if (max_profit < prices[idx] - min_price) {
                max_profit = prices[idx] - min_price;
            }
        }

        return max_profit;
    }
};