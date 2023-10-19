class Solution {
  public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        std::vector<int> prices(n, INT_MAX);

        prices[src] = 0;

        ++k;
        while (k-- != 0) {

            std::vector<int> temp = prices;

            for (const auto& flight : flights) {

                if (prices[flight[0]] != INT_MAX && prices[flight[0]] + flight[2] < temp[flight[1]]) {
                    temp[flight[1]] = prices[flight[0]] + flight[2];
                }
            }

            prices = temp;
        }

        return (prices[dst] == INT_MAX) ? -1 : prices[dst];
    }
};