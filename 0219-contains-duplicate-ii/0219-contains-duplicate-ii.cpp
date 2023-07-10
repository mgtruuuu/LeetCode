class Solution {
  public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        std::unordered_map<int, int> value2idx;
        
        for (auto idx = 0; idx != static_cast<int>(nums.size()); ++idx) {

            const auto p = value2idx.find(nums[idx]);

            if (p != value2idx.end() && (idx - p->second) <= k) {
                return true;
            }

            value2idx[nums[idx]] = idx;
        }

        return false;
    }
};