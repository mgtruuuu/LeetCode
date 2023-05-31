#include <array>
#include <string>
#include <unordered_map>
#include <vector>

constexpr auto len_alphabet = 26;
constexpr auto ascii_n_starting_char = static_cast<int>('a');
std::array<int, len_alphabet> alphabet_table;

class Solution {

  public:
    
    std::string str2anagram(const std::string& str)
    {
        constexpr int ascii_n_starting_char = static_cast<int>('a');

        alphabet_table.fill(0);
        for (const auto ch : str) {
            const auto idx = static_cast<int>(ch) - ascii_n_starting_char;

            alphabet_table[idx] += 1;
        }

        std::string res;
        res.reserve(len_alphabet * 2);

        for (auto idx = 0; idx < len_alphabet; ++idx) {
            if (alphabet_table[idx] != 0) {
                const char ch = static_cast<char>(idx + ascii_n_starting_char);
                const auto count_str = std::to_string(alphabet_table[idx]);

                res.push_back(ch);

                for (const auto num_digit : count_str) {
                    res.push_back(num_digit);
                }
            }
        }

        return res;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        std::unordered_map<std::string, std::vector<std::string>> hash_anagram2list;

        for (const auto& str : strs) {
            const auto anagram = str2anagram(str);
            hash_anagram2list[anagram].emplace_back(str);
        }

        std::vector<std::vector<std::string>> res;

        for (const auto& [k, v] : hash_anagram2list) {
            res.emplace_back(v);
        }

        return res;
    }
};