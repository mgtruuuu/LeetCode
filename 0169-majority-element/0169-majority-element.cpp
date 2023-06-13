class Solution {
  public:
    int majorityElement(vector<int>& nums)
    {
        unordered_map<int, int> hash;
        for (const auto num : nums) {
            ++hash[num];
        }

        auto max_val = nums[0];
        for (auto& [a, b] : hash) {
            if (b > hash[max_val])
                max_val = a;
        }
        return max_val;
    }
};