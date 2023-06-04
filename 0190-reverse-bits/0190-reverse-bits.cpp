class Solution {
  public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t res = 0;

        for (auto i = 0; i < 32; i++) {
            res <<= 1;
            res += n % 2;
            n >>= 1;
        }

        return res;
    }
};

// // class Solution {
// //   public:
// //     uint32_t reverseBits(uint32_t n)
// //     {
// //         std::bitset<32> bits{ n };
// //         for (size_t idx = 0; idx < 32 / 2; ++idx) {
// //             if (bits[idx] != bits[32 - idx - 1]) {
// //                 bits.flip(idx);
// //                 bits.flip(32 - idx - 1);
// //             }
// //         }

// //         return bits.to_ulong();
// //     }
// // };