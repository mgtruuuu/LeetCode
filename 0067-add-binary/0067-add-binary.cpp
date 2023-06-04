class Solution {
  public:
    void addDigits(const char& ch_a, const char& ch_b, bool& b_overflow, char& result);

    string addBinary(string a, string b)
    {
        std::string res;

        auto p_a = a.end() - 1;
        auto p_b = b.end() - 1;

        bool b_overflow = false;
        char digit;

        while (a.begin() <= p_a || b.begin() <= p_b) {

            if (p_a < a.begin()) {
                while (b.begin() <= p_b) {
                    addDigits('0', *p_b, b_overflow, digit);
                    res.push_back(digit);
                    --p_b;
                }

                break;
            }
            else if (p_b < b.begin()) {
                while (a.begin() <= p_a) {
                    addDigits(*p_a, '0', b_overflow, digit);
                    res.push_back(digit);
                    --p_a;
                }

                break;
            }

            addDigits(*p_a, *p_b, b_overflow, digit);
            res.push_back(digit);
            --p_a;
            --p_b;
        }

        if (b_overflow == true) {
            res.push_back('1');
        }

        for (std::size_t idx = 0; idx != res.size() / 2; ++idx) {
            std::swap(res[idx], res[res.size() - idx - 1]);
        }

        return res;
    }
};

void Solution::addDigits(const char& ch_a, const char& ch_b, bool& b_overflow, char& result)
{
    if (b_overflow == false) {
        if (ch_a == '0') {
            if (ch_b == '0') {
                result = '0';
            }
            else {
                result = '1';
            }
        }
        else {
            if (ch_b == '0') {
                result = '1';
            }
            else {
                b_overflow = true;
                result = '0';
            }
        }
    }
    else {
        if (ch_a == '0') {
            if (ch_b == '0') {
                b_overflow = false;
                result = '1';
            }
            else {
                result = '0';
            }
        }
        else {
            if (ch_b == '0') {
                result = '0';
            }
            else {
                result = '1';
            }
        }
    }
}