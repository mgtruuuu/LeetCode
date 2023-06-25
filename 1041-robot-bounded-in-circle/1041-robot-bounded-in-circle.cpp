class Solution {
  public:
    bool isRobotBounded(string instructions)
    {
        auto x = 0;
        auto y = 0;
        auto dir = 0; // 0:UP, 1:LEFT, 2:DOWN, 3:RIGHT

        for (const auto& ch : instructions) {
            switch (ch) {
            case 'R':
                dir += 1;
                if (dir == 4) {
                    dir = 0;
                }
                break;

            case 'L':
                dir -= 1;
                if (dir == -1) {
                    dir = 3;
                }
                break;

            default:
                switch (dir) {
                case 0:
                    ++y;
                    break;
                case 1:
                    --x;
                    break;
                case 2:
                    --y;
                    break;
                default:
                    ++x;
                    break;
                }

                break;
            }
        }

        if (dir == 0 && (x != 0 || y != 0)) {
            return false;
        }
        else {
            return true;
        }
    }
};