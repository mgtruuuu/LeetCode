class Solution {
  public:
    string removeDuplicates(string s)
    {
        std::string res;
        res.reserve(s.size());
        
        for (auto rit = s.cbegin(); rit != s.cend(); ++rit) {

            if (res.empty() == true) {

                res.push_back(*rit);

                continue;
            }

            if (res.back() == *rit) {

                res.erase(res.end() - 1);
            }
            else {

                res.push_back(*rit);
            }
        }

        return res;
    }
};



/*
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
*/