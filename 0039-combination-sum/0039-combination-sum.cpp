/*
// Approach 1: Backtracking (My sol)
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

        combinations.shrink_to_fit();
        return combinations;
    }
};
*/


///*
// Approach 1: Backtracking
class Solution {
  private:
    void backtracking(const std::vector<int>& candidates, const int target, const std::size_t idx_next,
                      std::vector<int>& combination, std::vector<std::vector<int>>& combinations)
    {
        if (target == 0) {

            combinations.push_back(combination);

            return;
        }
        else if (idx_next == candidates.size()) {
            return;
        }

        backtracking(candidates, target, idx_next + 1, combination, combinations);
        auto count = 0;
        auto part_sum = candidates[idx_next];
        while (part_sum <= target) {

            combination.push_back(candidates[idx_next]);
            backtracking(candidates, target - part_sum, idx_next + 1, combination, combinations);
            part_sum += candidates[idx_next];
            ++count;
        }
        combination.resize(combination.size() - count);
    }

  public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        std::vector<std::vector<int>> combinations;
        combinations.reserve(150);

        std::vector<int> combination;
        backtracking(candidates, target, 0, combination, combinations);

        return combinations;
    }
};
//*/
