class Solution {
  public:
    int maximumWealth(vector<vector<int>>& accounts)
    {
        auto max = std::numeric_limits<int>::min();

        for (const auto& account : accounts) {

            auto sum_account = std::accumulate(account.begin(), account.end(), 0);

            max = max < sum_account ? sum_account : max;
        }

        return max;
    }
};