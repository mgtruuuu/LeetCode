class Solution {
  private:
    void backtracking(const std::size_t idx_left, std::vector<int>& permutation, std::vector<std::vector<int>>& res)
    {
        if (idx_left == permutation.size()) {

            res.push_back(permutation);

            return;
        }

        for (auto idx_right = idx_left; idx_right != permutation.size(); ++idx_right) {

            std::swap(permutation[idx_left], permutation[idx_right]);
            backtracking(idx_left + 1, permutation, res);
            std::swap(permutation[idx_left], permutation[idx_right]);
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