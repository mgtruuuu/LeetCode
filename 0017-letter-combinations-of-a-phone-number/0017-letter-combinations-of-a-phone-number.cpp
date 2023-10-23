class Solution {
  private:
    const char* digit2letters[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    void backtracking(const std::string& digits, std::string& letters, std::vector<std::string>& res)
    {
        if (letters.size() == digits.size()) {

            res.push_back(letters);

            return;
        }

        const char* value = digit2letters[static_cast<std::size_t>(digits[letters.size()] - '0')];
        for (auto idx = std::size_t(0); idx != strlen(value); ++idx) {

            letters.push_back(value[idx]);
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