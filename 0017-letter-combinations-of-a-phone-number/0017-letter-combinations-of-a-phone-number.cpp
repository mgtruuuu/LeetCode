class Solution {
  private:
    std::unordered_map<char, std::string> digit2letter{
        { '2', "abc" }, { '3', "def" },  { '4', "ghi" }, { '5', "jkl" },
        { '6', "mno" }, { '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" }
    };

    void backTracking(const std::string& digits, const std::size_t idx, std::string& letter,
                      std::vector<std::string>& output)
    {
        if (idx == digits.size()) {
            output.emplace_back(letter);

            return;
        }

        const auto& str_value = digit2letter[digits[idx]];

        for (const auto c : str_value) {

            letter.push_back(c);
            backTracking(digits, idx + 1, letter, output);
            letter.pop_back();
        }
    }

  public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty() == true) {
            return {};
        }

        std::string letter;
        letter.reserve(digits.size());

        std::vector<std::string> res;
        res.reserve(256);

        backTracking(digits, 0, letter, res);

        res.shrink_to_fit();
        return res;
    }
};