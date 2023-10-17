class Solution {
  public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        const auto len_nums = static_cast<int>(nums.size());

        std::unordered_map<int, int> num2count;

        for (auto idx = 0; idx < std::min(k + 1, len_nums); ++idx) {

            if (++num2count[nums[idx]] == 2) {
                return true;
            }
        }

        for (auto idx = k + 1; idx < len_nums; ++idx) {

            --num2count[nums[idx - k - 1]];

            if (++num2count[nums[idx]] == 2) {
                return true;
            }
        }

        return false;
    }
};