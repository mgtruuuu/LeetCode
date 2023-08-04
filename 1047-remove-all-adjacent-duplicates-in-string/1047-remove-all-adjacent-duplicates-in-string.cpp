class Solution {
  public:
    string removeDuplicates(string s)
    {
        std::stack<char> chars;

        for (auto rit = s.crbegin(); rit != s.crend(); ++rit) {

            if (chars.empty() == true) {

                chars.push(*rit);

                continue;
            }

            if (chars.top() == *rit) {

                chars.pop();
            }
            else {

                chars.push(*rit);
            }
        }

        std::string res;
        while (chars.empty() == false) {

            res.push_back(chars.top());
            chars.pop();
        }

        return res;
    }
};