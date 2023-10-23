class Solution {
  private:
    void backtracking(const int n, const int k, std::vector<int>& combination, std::vector<std::vector<int>>& res)
    {
        if (combination.size() == k) {

            res.push_back(combination);

            return;
        }

        for (auto num = combination.empty() == true ? 1 : combination.back() + 1; num <= n; ++num) {

            combination.push_back(num);
            backtracking(n, k, combination, res);
            combination.pop_back();
        }
    }

    int getCombination(int n, int k)
    {
        if (k > n / 2) {
            k = n - k;
        }

        if (k == 0) {
            return 1;
        }

        auto numerator = n;
        auto denominator = 1;

        long res = 1;
        auto count = k;
        while (count-- != 0) {

            res *= (numerator--);
            res /= (denominator++);
        }

        return res;
    }

  public:
    vector<vector<int>> combine(int n, int k)
    {
        std::vector<int> combination;
        std::vector<std::vector<int>> res;
        res.reserve(getCombination(n, k));

        backtracking(n, k, combination, res);

        return res;
    }
};