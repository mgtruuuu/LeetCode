class Solution {
  public:
    void rotate(vector<int>& nums, int k)
    {
        const auto len_nums = nums.size();

        k %= len_nums;

        if (k == 0) {
            return;
        }

        if (k <= len_nums / 2) {
            std::vector<int> temp(k);

            memcpy(temp.data(), nums.data() + (len_nums - k), k * sizeof(int));

            for (auto idx = nums.size() - k; idx-- != 0;) {
                nums[idx + k] = nums[idx];
            }

            memcpy(nums.data(), temp.data(), k * sizeof(int));
        }
        else {

            k = len_nums - k;

            std::vector<int> temp(k);
            memcpy(temp.data(), nums.data(), k * sizeof(int));

            for (auto idx = std::size_t(0); idx != len_nums - k; ++idx) {
                nums[idx] = nums[idx + k];
            }

            memcpy(nums.data() + (len_nums - k), temp.data(), k * sizeof(int));
        }
    }
};