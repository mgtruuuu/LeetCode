class Solution {
  public:
    int romanToInt(string s)
    {
        auto res = 0;
        auto before_ch = '0';
        for (const auto& ch : s) {
            switch (ch) {
            case 'M':
                res += 1000;
                if (before_ch == 'C') {
                    res -= 200;
                }
                break;

            case 'D':
                res += 500;
                if (before_ch == 'C') {
                    res -= 200;
                }
                break;

            case 'C':
                res += 100;
                if (before_ch == 'X') {
                    res -= 20;
                }
                break;

            case 'L':
                res += 50;
                if (before_ch == 'X') {
                    res -= 20;
                }
                break;

            case 'X':
                res += 10;
                if (before_ch == 'I') {
                    res -= 2;
                }
                break;

            case 'V':
                res += 5;
                if (before_ch == 'I') {
                    res -= 2;
                }
                break;

            case 'I':
                res += 1;
                break;
            }

            before_ch = ch;
        }

        return res;
    }
};