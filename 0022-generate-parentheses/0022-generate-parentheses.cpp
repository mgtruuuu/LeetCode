class Solution {
  private:
    void backtracking(const int n, const int num_lefts, const int num_rights, std::string& combination,
                      std::vector<std::string>& combinations)
    {
        if (num_lefts == n && num_rights == n) {

            combinations.push_back(combination);

            return;
        }

        if (num_rights == n || num_lefts == num_rights) {
            combination.push_back('(');
            backtracking(n, num_lefts + 1, num_rights, combination, combinations);
            combination.pop_back();
        }
        else if (num_lefts == n) {
            combination.push_back(')');
            backtracking(n, num_lefts, num_rights + 1, combination, combinations);
            combination.pop_back();
        }
        else {
            combination.push_back(')');
            backtracking(n, num_lefts, num_rights + 1, combination, combinations);
            combination.pop_back();
            combination.push_back('(');
            backtracking(n, num_lefts + 1, num_rights, combination, combinations);
            combination.pop_back();
        }
    }

  public:
    vector<string> generateParenthesis(int n)
    {
        auto combination = std::string{};
        auto combinations = std::vector<std::string>{};
        backtracking(n, 0, 0, combination, combinations);

        return combinations;
    }
};