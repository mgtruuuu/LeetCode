class Solution {
  private:
    void backtrack(const int n, const int k, const int digit, std::vector<int>& combination,
                   std::vector<std::vector<int>>& combinations)
    {
        if (digit == k) {

            combinations.push_back(combination);

            return;
        }

        const auto iStart = combination.empty() ? 1 : combination.back() + 1;
        const auto iEnd = n - k + 1 + digit;

        for (auto i = iStart; i <= iEnd; ++i) {

            combination.push_back(i);
            backtrack(n, k, digit + 1, combination, combinations);
            combination.pop_back();
        }
    }

  public:
    vector<vector<int>> combine(int n, int k)
    {
        std::vector<std::vector<int>> res;
        std::vector<int> combination;

        backtrack(n, k, 0, combination, res);

        return res;
    }
};
