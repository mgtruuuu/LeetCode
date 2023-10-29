class Solution {
  public:
    vector<int> finalPrices(vector<int>& prices)
    {
        std::vector<int> res(prices.size());

        std::stack<int> s;
        for (auto idx = std::size_t(0); idx != prices.size(); ++idx) {

            while (s.empty() == false && prices[idx] <= prices[s.top()]) {

                res[s.top()] = prices[s.top()] - prices[idx];
                s.pop();
            }

            s.push(idx);
        }

        while (s.empty() == false) {

            res[s.top()] = prices[s.top()];
            s.pop();
        }

        return res;
    }
};