class Solution {
  public:
    int singleNumber(vector<int>& nums)
    {
        int bits[32]{};

        std::bitset<32> num_bitset{ 0 };
        for (const auto& num : nums) {
            num_bitset = num;

            for (std::size_t j = 0; j != 32; ++j) {
                if (num_bitset.test(j) == true) {
                    ++bits[j];
                }
            }
        }

        for (std::size_t idx = 0; idx != 32; ++idx) {
        }

        auto res = 0; // 0b0000'0000'0000'0000'0000'0000'0000'0000
        for (std::size_t idx = 0; idx != 32; ++idx) {

            if (bits[idx] % 3 != 0) {
                res |= (1 << idx);
            }
        }

        return res;
    }
};