class Solution {
public:
    void backTracking(const std::vector<int>& nums, const std::size_t idx, std::vector<int>& sub,
                      std::vector<std::vector<int>>& list_sub)
    {
        if (idx == nums.size()) {
            list_sub.push_back(sub);

            return;
        }

        backTracking(nums, idx + 1, sub, list_sub);

        sub.push_back(nums[idx]);
        backTracking(nums, idx + 1, sub, list_sub);
        sub.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        std::vector<int> sub;
        std::vector<std::vector<int>> list_sub;

        backTracking(nums, 0, sub, list_sub);

        return list_sub;
    }
};