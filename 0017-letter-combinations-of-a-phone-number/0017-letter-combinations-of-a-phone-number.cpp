
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  private:
    std::unordered_map<char, std::string> hash{ { '2', "abc" }, { '3', "def" },  { '4', "ghi" }, { '5', "jkl" },
                                                { '6', "mno" }, { '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" } };

    void backTracking(const std::string& digits, const std::size_t idx, std::string& letter,
                      std::vector<std::string>& output)
    {
        if (idx == digits.size()) {
            output.emplace_back(letter);

            return;
        }

        const auto& str_value = hash.at(digits[idx]);

        for (const auto& c : str_value) {
            letter.push_back(c);
            backTracking(digits, idx + 1, letter, output);
            letter.pop_back();
        }
    }

  public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty() == true) {
            return std::vector<std::string>{};
        }

        std::string empty;
        std::vector<std::string> res;

        backTracking(digits, 0, empty, res);

        return res;
    }
};