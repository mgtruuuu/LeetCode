class Solution {
  public:
    int maxProfit(vector<int>& prices)
    {
        const auto len_prices = prices.size();

        auto max_profit = 0;
        auto valley = INT_MAX;
        auto peak = INT_MIN;

        auto idx = std::size_t(0);
        while (idx != len_prices) {

            while (idx != len_prices && prices[idx] <= valley) {
                valley = prices[idx++];
            }

            peak = valley;

            while (idx != len_prices && peak <= prices[idx]) {
                peak = prices[idx++];
            }

            max_profit += peak - valley;
            valley = peak;
        }

        return max_profit;
    }
};



/*
// Approach 3: Simple One Pass
class Solution {
  public:
    int maxProfit(vector<int>& prices)
    {
        auto res = 0;
        for (auto idx = std::size_t(1); idx != prices.size(); ++idx) {
            if (prices[idx - 1] < prices[idx]) {
                res += (prices[idx] - prices[idx - 1]);
            }
        }

        return res;
    }
};
*/