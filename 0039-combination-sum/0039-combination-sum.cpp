class Solution {
  private:
    void backtracking(const std::vector<int>& candidates, const int target, std::vector<int>& combination_counts,
                      std::vector<std::vector<int>>& combinations)
    {
        if (combination_counts.size() == candidates.size()) {

            if (target != 0) {
                return;
            }

            std::vector<int> combination;
            for (auto idx = std::size_t(0); idx != combination_counts.size(); ++idx) {
                auto count = combination_counts[idx];
                while (count-- != 0) {
                    combination.push_back(candidates[idx]);
                }
            }

            combinations.push_back(std::move(combination));

            return;
        }

        for (auto count = 0, part = 0; part <= target; ++count, part += candidates[combination_counts.size()]) {

            combination_counts.push_back(count);
            backtracking(candidates, target - part, combination_counts, combinations);
            combination_counts.pop_back();
        }
    }

  public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        std::vector<std::vector<int>> combinations;
        combinations.reserve(150);

        std::vector<int> combination_counts;
        combination_counts.reserve(candidates.size());
        backtracking(candidates, target, combination_counts, combinations);

        return combinations;
    }
};