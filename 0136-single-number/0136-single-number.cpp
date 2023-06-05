class Solution {
  public:
    int singleNumber(vector<int>& nums)
    {
        std::bitset<60001> bits{ 0 };

        for (const auto& num : nums) {
            bits.flip(num + 30000);
        }

        for (auto num = -30000; num != 30001; ++num) {
            if (bits.test(num + 30000) == true) {
                return num;
            }
        }

        return 0;
    }
};