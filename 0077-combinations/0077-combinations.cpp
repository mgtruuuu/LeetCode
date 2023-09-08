class Solution {
  private:
    void backtrack(const int n, const int k, const int first_num, std::vector<int>& combination,
                   std::vector<std::vector<int>>& combinations)
    {
        if (static_cast<int>(combination.size()) == k) {

            combinations.push_back(combination);

            return;
        }

        const auto iEnd = n - k + 1 + static_cast<int>(combination.size());
        for (auto i = first_num; i <= iEnd; ++i) {

            combination.push_back(i);
            backtrack(n, k, i + 1, combination, combinations);
            combination.pop_back();
        }
    }

  public:
    vector<vector<int>> combine(int n, int k)
    {
        std::vector<std::vector<int>> res;
        std::vector<int> combination;

        backtrack(n, k, 1, combination, res);

        return res;
    }
};
