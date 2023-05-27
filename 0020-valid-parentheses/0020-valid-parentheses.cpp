#include <algorithm>
#include <array>
#include <iterator>
#include <string>
#include <vector>

class Solution {
public:
    bool isValid(std::string s) {

        bool res = true;

        std::array<char, 3> open_brackets{ '(', '{', '[' };
        std::array<char, 3> close_brackets{ ')', '}', ']' };

        if (s.size() % 2 != 0)
        {
            res = false;
            return res;
        }


        std::vector<char> stack_open_brackets;
        stack_open_brackets.reserve(s.size());


        for (const auto ch : s)
        {
            if (std::find(open_brackets.begin(), open_brackets.end(), ch) != open_brackets.end())
            {
                stack_open_brackets.emplace_back(ch);
            }
            else
            {
                if (stack_open_brackets.empty() == true)
                {
                    res = false;
                    break;
                }

                const auto idx_open_bracket =
                    std::distance(open_brackets.begin(), std::find(open_brackets.begin(), open_brackets.end(), stack_open_brackets.back()));

                const auto idx_close_bracket =
                    std::distance(close_brackets.begin(), std::find(close_brackets.begin(), close_brackets.end(), ch));

                if (idx_open_bracket == idx_close_bracket)
                {
                    stack_open_brackets.pop_back();
                }
                else
                {
                    res = false;
                    break;
                }
            }
        }

        if (stack_open_brackets.empty() == false)
        {
            res = false;
        }

        return res;
    };
};