/*
// Approach 1: Linear Scan - Generalized (using LIS)
class Solution {
  public:
    bool increasingTriplet(vector<int>& nums)
    {
        auto subs = std::vector<int>{ nums.front() };
        subs.reserve(2);

        for (const auto num : nums) {

            if (subs.back() < num) {
                if (subs.size() == 2) {
                    return true;
                }
                else {
                    subs.push_back(num);
                }
            }
            else {
                *std::lower_bound(subs.begin(), subs.end(), num) = num;
            }
        }

        return false;
    }
};
*/


class Solution {
  public:
    bool increasingTriplet(vector<int>& nums)
    {
        auto subs = std::vector<int>{ nums.front() };
        subs.reserve(2);

        for (const auto num : nums) {

            if (subs.back() < num) {
                if (subs.size() == 2) {
                    return true;
                }
                else {
                    subs.push_back(num);
                }
            }
            else if (subs.front() < num) {
                subs.back() = num;
            }
            else {
                subs.front() = num;
            }

        }

        return false;
    }
};