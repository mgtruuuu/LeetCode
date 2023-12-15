class Solution {
  public:
    string decodeString(string s)
    {
        std::stack<int> s_int;
        std::stack<std::string> s_str;

        s_int.push(1);
        s_str.push(std::string());

        auto num = 0;
        for (const auto ch : s) {

            if (ch == '[') {

                s_int.push(num);
                num = 0;

                s_str.push(std::string());
            }
            else if (ch == ']') {

                auto n = s_int.top();

                std::string temp;
                temp.reserve(n * s_str.top().size());
                while (n-- != 0) {
                    temp += s_str.top();
                }

                s_int.pop();
                s_str.pop();
                s_str.top() += temp;
            }
            else if (ch >= '0' && ch <= '9') {

                num *= 10;
                num += ch - '0';
            }
            else {
                // 'a' ~ 'z'
                s_str.top().push_back(ch);
            }
        }

        return s_str.top();
    }
};