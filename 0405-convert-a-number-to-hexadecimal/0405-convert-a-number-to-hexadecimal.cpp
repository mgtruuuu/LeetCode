class Solution {
  public:
    string toHex(int num)
    {
        std::bitset<32> bits;

        auto is_positive = true;
        if (num == 0) {
            return "0";
        }
        else if (num == std::numeric_limits<int>::min()) {
            return "80000000";
        }
        else if (num < 0) {
            is_positive = false;
            num = -num;
        }

        for (auto idx = std::size_t(0); idx != 32; ++idx) {
            auto r = num;
            num /= 2;
            r -= 2 * num;

            if (r == 1) {
                bits.set(idx);
            }
            else {
                bits.reset(idx);
            }
        }

        if (is_positive == false) {

            bits.flip();

            auto idx = std::size_t(0);
            while (bits[idx] == true) {
                bits.flip(idx);
                ++idx;
            }
            bits.flip(idx);
        }

        std::string res;
        auto digit_hex = 0;
        auto first_zero_marker = false;
        for (auto idx = std::size_t(32); idx-- != 0;) {

            if (bits[idx] == true) {

                auto pow = 1;
                for (auto i = 0; i != idx % 4; ++i) {
                    pow *= 2;
                }

                digit_hex += pow;
            }

            if (idx % 4 == 0) {
                switch (digit_hex) {
                case 10:
                    res.push_back('a');
                    break;
                case 11:
                    res.push_back('b');
                    break;
                case 12:
                    res.push_back('c');
                    break;
                case 13:
                    res.push_back('d');
                    break;
                case 14:
                    res.push_back('e');
                    break;
                case 15:
                    res.push_back('f');
                    break;
                case 0:
                    if (res.empty() == true) {
                        break;
                    }
                default:
                    res.push_back(static_cast<int>('0') + digit_hex);
                    break;
                }

                digit_hex = 0;
            }
        }

        return res;
    }
};