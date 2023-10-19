class Solution {
  public:
    int reverse(int x)
    {
        if (x == 0) {
            return 0;
        }

        std::stack<int> s;
        while (x != 0) {
            const auto quotient = x / 10;
            s.push(x - 10 * quotient);
            x = quotient;
        }

        auto res = 0;
        const auto len_q = static_cast<int>(s.size());
        
        for (auto i = 0; i != len_q - 1; ++i) {

            auto mul = s.top();
            for (auto j = 0; j != i; ++j) {
                mul *= 10;
            }

            res += mul;
            s.pop();
        }

        {
            auto mul = s.top();
            
            if (len_q == 10 && (mul > 2 || mul < -2)) {
                return 0;
            }
            
            for (auto j = 0; j != len_q - 1; ++j) {
                mul *= 10;
            }

            if (len_q == 10) {

                
                if ((res > 0 && int(0x7FFFFFFF) - res < mul) || res < 0 && (int(0x80000000) - res > mul)) {
                    return 0;
                }
            }

            res += mul;
            s.pop();
        }

        return res;
    }
};