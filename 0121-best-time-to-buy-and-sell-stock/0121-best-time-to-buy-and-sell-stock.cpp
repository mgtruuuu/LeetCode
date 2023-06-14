class Solution {
  public:
    int maxProfit(vector<int>& prices)
    {
        auto min_price = std::numeric_limits<int>::max();
        auto max_profit = 0;
        for (auto i = std::size_t(0); i < prices.size(); ++i) {
            if (prices[i] < min_price) {
                min_price = prices[i];
                
                continue;
            }
            
            if (prices[i] - min_price > max_profit) {
                max_profit = prices[i] - min_price;
            }    
        }
        
        return max_profit;
    }
};