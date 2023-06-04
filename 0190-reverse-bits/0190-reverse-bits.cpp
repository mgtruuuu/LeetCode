class Solution {
  public:
    uint32_t reverseBits(uint32_t n)
    {
        std::bitset<32> bits{ n };
        for (size_t idx = 0; idx < 32 / 2; ++idx) {
            if (bits[idx] != bits[32 - idx - 1]) {
                bits.flip(idx);
                bits.flip(32 - idx - 1);
            }
        }

        return bits.to_ulong();
    }
};