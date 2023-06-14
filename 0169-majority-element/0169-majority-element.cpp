class Solution {
  public:
    int majorityElement(vector<int>& nums)
    {
        std::array<int, 32> bits_count;
        bits_count.fill(0);

        for (const auto& num : nums) {

            auto num_bits = static_cast<uint32_t>(num);
            auto idx = std::size_t(0);

            while (num_bits != 0) {
                if (num_bits & 1) {
                    ++bits_count[idx];
                }

                ++idx;
                num_bits >>= 1;
            }
        }

        auto res = std::size_t(0);

        for (std::size_t idx = 0; idx != bits_count.size(); ++idx) {
            if (bits_count[idx] > (nums.size() / 2)) {
                auto pow_two = std::size_t(1);
                for (std::size_t i = 0; i != idx; ++i) {
                    pow_two *= 2;
                }

                res += pow_two;
            }
        }

        return static_cast<int>(res);
    }
};