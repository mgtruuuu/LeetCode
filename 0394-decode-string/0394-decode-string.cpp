#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <utility>


class Solution {
  public:
    string decodeString(string s)
    {
        std::stack<std::pair<int, std::string>> list_cnt_str;

        std::string res;
        list_cnt_str.emplace(-1, res);

        auto num_to_push = 0;
        for (const auto ch : s) {

            if (isdigit(ch)) {
                num_to_push *= 10;
                num_to_push += static_cast<int>(ch) - static_cast<int>('0');
            }
            else if (islower(ch)) {
                list_cnt_str.top().second.push_back(ch);
            }
            else if (ch == '[') {
                list_cnt_str.emplace(num_to_push, std::string{});
                num_to_push = 0;
            }
            else // ch == ']'
            {
                const auto cnt_from_top = list_cnt_str.top().first;
                const auto str_from_top = list_cnt_str.top().second; // move????? check
                list_cnt_str.pop();

                for (auto cnt = cnt_from_top; cnt != 0; --cnt) {
                    for (const auto ch : str_from_top) {
                        list_cnt_str.top().second.push_back(ch);
                    }
                }
            }
        }

        return list_cnt_str.top().second;
    }
};