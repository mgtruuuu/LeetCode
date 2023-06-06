class Solution {
  public:
    int singleNumber(vector<int>& arr)
    {
        const auto size_arr = arr.size(); // extracting the size of the array

        // traverse from the array
        for (std::size_t idx = 0; idx != size_arr - 1; ++idx) {
            arr[idx + 1] = arr[idx] ^ arr[idx + 1]; // (prev answer xor current index)
        }

        return arr[size_arr - 1]; // return left over element
    }
};



// class Solution {
//   public:
//     int singleNumber(vector<int>& nums)
//     {
//         std::bitset<60001> bits{ 0 };

//         for (const auto& num : nums) {
//             bits.flip(num + 30000);
//         }

//         for (auto num = -30000; num != 30001; ++num) {
//             if (bits.test(num + 30000) == true) {
//                 return num;
//             }
//         }

//         return 0;
//     }
// };