class Solution {
  public:
    bool increasingTriplet(vector<int>& nums)
    {
        auto subs = std::vector<int>();
        subs.reserve(2);
        subs.push_back(nums.front());

        for (auto idx = std::size_t(1); idx != nums.size(); ++idx) {

            if (subs.back() < nums[idx]) {

                if (subs.size() == std::size_t(2)) {
                    return true;
                }
                
                subs.push_back(nums[idx]);
            }
            else {
                *std::lower_bound(subs.begin(), subs.end(), nums[idx]) = nums[idx];
            }
        }

        return false;
    }
};