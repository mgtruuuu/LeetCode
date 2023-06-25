class Solution {
  public:
    bool judgeCircle(string moves)
    {
        auto x = 0;
        auto y = 0;
        for (const auto& move : moves) {
            switch (move) {
            case 'R':
                x += 1;
                break;

            case 'L':
                x -= 1;
                break;

            case 'U':
                y += 1;
                break;

            // case 'D'
            default:
                y -= 1;
                break;
            }
        }

        if (x == 0 && y == 0) {
            return true;
        }
        else {
            return false;
        }
    }
};