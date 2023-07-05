class Solution {
  public:
    uint32_t reverseBits(uint32_t n)
    {
        constexpr auto len_bits = 32;

        for (auto idx = 0; idx != len_bits / 2; ++idx) {

            const uint32_t bit_left = 1 << (31 - idx);
            const uint32_t bit_right = 1 << idx;

            if ((n & bit_left) == 0 && (n & bit_right) != 0) {
                n += (bit_left - bit_right);
            }
            else if ((n & bit_left) != 0 && (n & bit_right) == 0) {
                n -= (bit_left - bit_right);
            }
        }

        return n;
    }
};



// // class Solution {
// //   public:
// //     uint32_t reverseBits(uint32_t n)
// //     {
// //         constexpr auto len_bit = 32;
// //         uint32_t res = 0;

// //         for (auto i = 0; i < len_bit; ++i) {
// //             res <<= 1;
// //             res += (n & 1);
// //             n >>= 1;
// //         }

// //         return res;
// //     }
// // };
