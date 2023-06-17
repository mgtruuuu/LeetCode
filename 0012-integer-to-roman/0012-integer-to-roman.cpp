class Solution {
  public:
    char roman_symbols[4][2] = { { 'I', 'V' }, { 'X', 'L' }, { 'C', 'D' }, { 'M', '+' } };

    void digitToSymbol(const int digit, const int idx_place, std::string& symbols)
    {
        switch (digit) {

        case 3:
        case 8:
            symbols.push_back(roman_symbols[idx_place][0]);

        case 2:
        case 7:
            symbols.push_back(roman_symbols[idx_place][0]);

        case 1:
        case 6:
            symbols.push_back(roman_symbols[idx_place][0]);
            break;

        case 4:
            symbols.push_back(roman_symbols[idx_place][1]);
            symbols.push_back(roman_symbols[idx_place][0]);
            break;

        case 9:
            symbols.push_back(roman_symbols[idx_place + 1][0]);
            symbols.push_back(roman_symbols[idx_place][0]);
            break;

        default: // case 0, 5:
            break;
        }

        if (4 < digit && digit < 9) {
            symbols.push_back(roman_symbols[idx_place][1]);
        }
    }

    string intToRoman(int num)
    {

        std::string res;
        auto idx_place = 0;

        while (num != 0) {

            const auto r = num % 10;
            num -= r;
            num /= 10;

            digitToSymbol(r, idx_place, res);

            ++idx_place;
        }

        std::reverse(res.begin(), res.end());

        return res;
    }
};