class Solution {
  public:
    int singleNumber(vector<int>& nums)
    {
        int bits[32]{};
        
        for (const auto& num : nums) {

            auto num_bitset = num;
            std::size_t idx = 0;

            while (num_bitset != 0) {
  
                if (num_bitset & 1) {
                    ++bits[idx];
                }

                ++idx;
                
                num_bitset = static_cast<int>(static_cast<unsigned int>(num_bitset) >> 1);
            }
        }
        
        auto res = 0; // 0b0000'0000'0000'0000'0000'0000'0000'0000
        for (std::size_t idx = 0; idx != 32; ++idx) {

            if (bits[idx] % 3 != 0) {
                res |= static_cast<int>(1 << idx);
            }
        }
        
        return res;
    }
};



// class Solution {
//   public:
//     int singleNumber(vector<int>& nums)
//     {
//         int bits[32]{};

//         std::bitset<32> num_bitset{ 0 };
//         for (const auto& num : nums) {
//             num_bitset = num;

//             for (std::size_t j = 0; j != 32; ++j) {
//                 if (num_bitset.test(j) == true) {
//                     ++bits[j];
//                 }
//             }
//         }

//         for (std::size_t idx = 0; idx != 32; ++idx) {
//         }

//         auto res = 0; // 0b0000'0000'0000'0000'0000'0000'0000'0000
//         for (std::size_t idx = 0; idx != 32; ++idx) {

//             if (bits[idx] % 3 != 0) {
//                 res |= (1 << idx);
//             }
//         }

//         return res;
//     }
// };