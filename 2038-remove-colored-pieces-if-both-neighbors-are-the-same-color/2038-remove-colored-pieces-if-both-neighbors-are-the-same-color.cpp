///*
// Approach 1-1: Count
class Solution {
  public:
    bool winnerOfGame(string colors)
    {
        auto res = 0;

        for (auto i = 1; i < static_cast<int>(colors.size()) - 1; ++i) {
            if (colors[i - 1] == colors[i] && colors[i] == colors[i + 1]) {
                colors[i] == 'A' ? ++res : --res;
            }
        }

        return res > 0;
    }
};
//*/



/*
// Approach 1-2: Count (My sol)
class Solution {
  public:
    bool winnerOfGame(string colors)
    {
        auto res = 0;

        auto count = 0;
        auto prev = colors.front() == 'A' ? 'B' : 'A';

        for (const auto color : colors) {

            if (prev == color) {

                ++count;

                continue;
            }

            if (count > 2) {

                count -= 2;

                if (prev == 'A') {
                    res += count;
                }
                else {
                    res -= count;
                }
            }

            count = 1;
            prev = color;
        }

        if (count > 2) {

            count -= 2;

            if (prev == 'A') {
                res += count;
            }
            else {
                res -= count;
            }
        }

        return res > 0;
    }
};
*/