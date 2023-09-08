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
    
    unsigned long long getCombination(const int n, int r);

  public:
    vector<vector<int>> combine(int n, int k)
    {
        std::vector<std::vector<int>> res;
        res.reserve(getCombination(n, k));

        std::vector<int> combination;
        combination.reserve(k);

        backtrack(n, k, 1, combination, res);

        return res;
    }
};

unsigned long long Solution::getCombination(const int n, int r)
{
    r = std::min(r, n - r);

    unsigned long long numerator = 1;
    for (auto i = n - r + 1; i <= n; ++i) {
        numerator *= i;
    }

    unsigned long long denominator = 1;
    for (auto i = 1; i <= r; ++i) {
        denominator *= i;
    }

    return (numerator / denominator);
}