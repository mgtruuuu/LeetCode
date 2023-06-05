class Solution {
  public:
    int hammingWeight(uint32_t n)
    {
        const std::bitset<32> bits{ n };                
        
        return std::bitset<32>(n).count();
    }
};

// // class Solution {
// //   public:
// //     int hammingWeight(uint32_t n)
// //     {
// //         auto count = 0;
// //         while (n != 0) {
// //             if (n & 1) {
// //                 ++count;
// //             }

// //             n = n >> 1;
// //         }

// //         return count;
// //     }
// // };