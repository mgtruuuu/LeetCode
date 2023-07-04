class Solution {
  public:
    int largestUniqueNumber(vector<int>& nums)
    {
        std::unordered_map<int, int> num2count;

        for (const auto num : nums) {
            ++num2count[num];
        }

        auto res = -1;

        for (const auto& [k, v] : num2count) {

            if (v == 1 && res < k) {
                res = k;
            }
        }

        return res;
    }
};