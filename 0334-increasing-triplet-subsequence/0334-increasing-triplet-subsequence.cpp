class Solution {
  public:
    bool increasingTriplet(vector<int>& nums)
    {
        auto subs = std::vector<int>{ nums.front() };

        for (auto idx = std::size_t(1); idx != nums.size(); ++idx) {

            if (subs.back() < nums[idx]) {

                subs.push_back(nums[idx]);

                if (subs.size() == std::size_t(3)) {
                    return true;
                }
            }
            else {
                *std::lower_bound(subs.begin(), subs.end(), nums[idx]) = nums[idx];
            }
        }

        return false;
    }
};