class Solution {
  public:
    int calculate(string s)
    {
        constexpr char plus_minus[2]{ '+', '-' };
        constexpr char mul_div[2]{ '*', '/' };
        constexpr auto ascii_start_point = static_cast<int>('0');

        auto accum_num{ 0 };
        auto chunk_num{ 1 };
        auto recent_num_to_read{ 0 };
        auto idx_plus_minus{ 0 }; // +
        auto idx_mul_div{ 0 };    //

        const auto ss = s + "+";
        for (const auto ch : ss) {

            if (isdigit(ch)) {
                recent_num_to_read *= 10;
                recent_num_to_read += (static_cast<int>(ch) - ascii_start_point);
            }
            else if (ch == ' ') {
                continue;
            }
            else {

                switch (ch) {
                case plus_minus[0]:

                    (idx_mul_div == 0) ? (chunk_num *= recent_num_to_read) : chunk_num /= recent_num_to_read;

                    (idx_plus_minus == 0) ? (accum_num += chunk_num) : (accum_num -= chunk_num);

                    idx_plus_minus = 0;
                    chunk_num = 1;
                    idx_mul_div = 0;
                    break;

                case plus_minus[1]:

                    (idx_mul_div == 0) ? (chunk_num *= recent_num_to_read) : chunk_num /= recent_num_to_read;

                    (idx_plus_minus == 0) ? (accum_num += chunk_num) : (accum_num -= chunk_num);

                    idx_plus_minus = 1;
                    chunk_num = 1;
                    idx_mul_div = 0;
                    break;

                case mul_div[0]:

                    (idx_mul_div == 0) ? (chunk_num *= recent_num_to_read) : chunk_num /= recent_num_to_read;

                    idx_mul_div = 0;

                    break;

                case mul_div[1]:

                    (idx_mul_div == 0) ? (chunk_num *= recent_num_to_read) : chunk_num /= recent_num_to_read;

                    idx_mul_div = 1;

                    break;

                default:;
                }

                recent_num_to_read = 0;
            }
        }

        return accum_num;
    }
};