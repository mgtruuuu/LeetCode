class Solution {
  private:
    const std::string digit2letters[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    void backtracking(const std::string& digits, std::string& letters, std::vector<std::string>& res)
    {
        if (letters.size() == digits.size()) {

            res.push_back(letters);

            return;
        }

        const auto idx = letters.size();
        for (const auto ch : digit2letters[static_cast<int>(digits[idx] - '0')]) {

            letters.push_back(ch);
            backtracking(digits, letters, res);
            letters.pop_back();
        }
    }

  public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty() == true) {
            return {};
        }

        std::vector<std::string> res;
        std::string empty;
        backtracking(digits, empty, res);

        return res;
    }
};
