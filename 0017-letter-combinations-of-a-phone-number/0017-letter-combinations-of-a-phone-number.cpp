class Solution {
  private:
    std::unordered_map<char, std::string> digit2letters{ { '2', "abc" }, { '3', "def" }, { '4', "ghi" },
                                                         { '5', "jkl" }, { '6', "mno" }, { '7', "pqrs" },
                                                         { '8', "tuv" }, { '9', "wxyz" } };
    
    void backtracking(const std::string& digits, std::string& letters, std::vector<std::string>& res)
    {
        if (letters.size() == digits.size()) {

            res.push_back(letters);

            return;
        }

        for (const auto ch : digit2letters[digits[letters.size()]]) {

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