/*
// Approach 1-1: Linear Scan - Generalized (using LIS)
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


// Approach 1-2: Linear Scan
class Solution {
  public:
    bool increasingTriplet(vector<int>& nums)
    {
        auto first = INT_MAX;
        auto second = INT_MAX;

        for (const auto num : nums) {

            if (num <= first) {
                first = num;
            }
            else if (num <= second) {
                second = num;
            }
            else {
                return true;
            }
        }

        return false;
    }
};