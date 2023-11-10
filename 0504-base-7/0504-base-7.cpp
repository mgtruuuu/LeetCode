class Solution {
  public:
    string convertToBase7(int num)
    {
        std::string res;
        bool is_negative = false;

        if (num < 0) {

            is_negative = true;
            num = -num;
        }



        do {

            const auto& quot_rem = div(num, 7);

            res.push_back('0' + quot_rem.rem);

            num = quot_rem.quot;
        }
        while (num != 0);

        if (is_negative == true) {
            res.push_back('-');
        }
        
        std::reverse(res.begin(), res.end());
        return res;
    }
};