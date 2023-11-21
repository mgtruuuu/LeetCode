// Approach 1: Backtracking, Keep Candidate Valid
class Solution {
  private:
    void generateParenthesisHelper(const int n, const int delta, std::string& combination,
                                   std::vector<std::string>& combinations)
    {
        if (combination.size() == 2 * n) {

            combinations.push_back(combination);
            return;
        }

        // '('
        if (delta < n) {

            combination.push_back('(');
            generateParenthesisHelper(n, delta + 1, combination, combinations);
            combination.pop_back();
        }

        // ')'
        if (delta * 2 > combination.size()) {
            combination.push_back(')');
            generateParenthesisHelper(n, delta, combination, combinations);
            combination.pop_back();
        }
    }

  public:
    vector<string> generateParenthesis(int n)
    {
        std::string combination;
        std::vector<std::string> combinations;

        generateParenthesisHelper(n, 0, combination, combinations);
        return combinations;
    }
};



// Approach 2: Divide and Conquer
// ??