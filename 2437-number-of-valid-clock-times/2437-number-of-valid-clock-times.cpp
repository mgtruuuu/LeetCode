class Solution {
  public:
    int countTime(string time)
    {
        auto choices = 1;

        int numbers[5] = { 3, 10, -1, 6, 10 };

        const auto hh = time.substr(0, 2);
        auto hh_reverse = hh;
        std::reverse(hh_reverse.begin(), hh_reverse.end());

        if (hh == "??") {
            choices *= 24;
        }
        else if (hh[0] == '?') {

            if (hh_reverse[0] - '0' > 3) {
                numbers[0] -= 1;
            }

            choices *= numbers[0];
        }
        else if (hh[1] == '?') {

            if (hh_reverse[1] - '0' == 2) {
                numbers[1] -= 6;
            }

            choices *= numbers[1];
        }

        for (auto idx = 3; idx != 5; ++idx) {
            if (time[idx] == '?') {
                choices *= numbers[idx];
            }
        }

        return choices;
    }
};