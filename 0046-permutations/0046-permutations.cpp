class Solution {
  private:
    void backtracking(const std::size_t idx_next, std::vector<int>& permutation, std::vector<std::vector<int>>& res)
    {
        if (idx_next == permutation.size()) {

            res.push_back(permutation);

            return;
        }

        for (auto idx = idx_next; idx != permutation.size(); ++idx) {

            std::swap(permutation[idx_next], permutation[idx]);
            backtracking(idx_next + 1, permutation, res);
            std::swap(permutation[idx_next], permutation[idx]);
        }
    }

    int getFactorial(int n)
    {
        auto res = 1;

        while (n != 0) {
            res *= n--;
        }

        return res;
    }

  public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        std::vector<std::vector<int>> res;
        res.reserve(getFactorial(nums.size()));

        auto permutation = nums;

        backtracking(0, permutation, res);

        return res;
    }
};