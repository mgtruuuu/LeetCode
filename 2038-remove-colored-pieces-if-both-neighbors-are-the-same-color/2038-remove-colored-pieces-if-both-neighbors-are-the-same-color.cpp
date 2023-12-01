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
        
        std::cout << res << std::endl;

        
        return res > 0;
    }
};