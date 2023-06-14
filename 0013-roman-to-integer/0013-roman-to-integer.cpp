class Solution {
  public:
    int romanToInt(string s)
    {
        std::unordered_map<char, int> hash;
        hash['M'] = 1000;
        hash['D'] = 500;
        hash['C'] = 100;
        hash['L'] = 50;
        hash['X'] = 10;
        hash['V'] = 5;
        hash['I'] = 1;

        auto was_hundred = false;
        auto was_ten = false;
        auto was_one = false;

        auto res = 0;
        for (const auto& c : s) {
            if (was_hundred == true && c == 'M') {
                res -= 100;
                res += 900;

                was_hundred = false;
                continue;
            }
            else if (was_hundred == true && c == 'D') {
                res -= 100;
                res += 400;

                was_hundred = false;
                continue;
            }

            if (was_ten == true && c == 'C') {
                res -= 10;
                res += 90;

                was_ten = false;
                continue;
            }
            else if (was_ten == true && c == 'L') {
                res -= 10;
                res += 40;

                was_ten = false;
                continue;
            }

            if (was_one == true && c == 'X') {
                res -= 1;
                res += 9;

                was_one = false;
                continue;
            }
            else if (was_one == true && c == 'V') {
                res -= 1;
                res += 4;

                was_one = false;
                continue;
            }

            res += hash[c];

            if (c == 'C') {
                was_hundred = true;
            }

            if (c == 'X') {
                was_ten = true;
            }

            if (c == 'I') {
                was_one = true;
            }
        }

        return res;
    }
};