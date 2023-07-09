class Solution {
  public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        std::unordered_map<int, int> value2idx;

        const auto len_nums = static_cast<int>(nums.size());

        const auto min = std::min(k, len_nums);

        for (auto idx = 0; idx != min; ++idx) {

            if (value2idx.find(nums[idx]) != value2idx.end()) {
                return true;
            }

            value2idx[nums[idx]] = idx;
        }

        for (auto idx = min; idx != static_cast<int>(nums.size()); ++idx) {

            const auto p = value2idx.find(nums[idx]);

            if (p != value2idx.end() && (idx - p->second) <= k) {
                return true;
            }

            value2idx[nums[idx]] = idx;
        }

        return false;
    }
};