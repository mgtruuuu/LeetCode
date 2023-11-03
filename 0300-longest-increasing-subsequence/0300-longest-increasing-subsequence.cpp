/*
// Approach 1: Dynamic Programming
class Solution {
  public:
    int lengthOfLIS(vector<int>& nums)
    {
        auto res = 1;
        std::vector<int> dps(nums.size());

        for (auto idx = std::size_t(0); idx != nums.size(); ++idx) {

            dps[idx] = 1;

            for (auto idx_left = std::size_t(0); idx_left != idx; ++idx_left) {

                if (nums[idx_left] < nums[idx] && dps[idx] < dps[idx_left] + 1) {
                    dps[idx] = dps[idx_left] + 1;
                }
            }

            if (res < dps[idx]) {
                res = dps[idx];
            }
        }

        return res;
    }
};
*/


/*
// Approach 2: Intelligently Build a Subsequence (use while)
class Solution {
  public:
    int lengthOfLIS(vector<int>& nums)
    {
        std::vector<int> subs{ nums.front() };

        for (auto idx = std::size_t(1); idx != nums.size(); ++idx) {

            auto idx_left = subs.size();
            --idx_left;
            
            while (subs[idx_left] >= nums[idx] && idx_left-- != 0) {
            }
            
            if (++idx_left == subs.size()) {
                subs.push_back(nums[idx]);
            }
            else {
                subs[idx_left] = nums[idx];
            }
        }

        return subs.size();
    }
};
*/


/*
// Approach 3-1: Improve With Binary Search
class Solution {
  private:
    std::size_t binarySearch(std::vector<int>& subs, int num)
    {
        auto idx_left = 0;
        auto idx_right = static_cast<int>(subs.size()) - 1;

        while (idx_left <= idx_right) {

            const auto idx_mid = (idx_left + idx_right) / 2;

            if (subs[idx_mid] < num) {
                idx_left = idx_mid + 1;
            }
            else {
                idx_right = idx_mid - 1;
            }
        }

        return idx_left;
    }

  public:
    int lengthOfLIS(vector<int>& nums)
    {
        std::vector<int> subs{ nums.front() };

        for (const auto num : nums) {

            const auto idx_insert = binarySearch(subs, num);

            if (idx_insert == subs.size()) {
                subs.push_back(num);
            }
            else {
                subs[idx_insert] = num;
            }
        }

        return subs.size();
    }
};
*/


///*
// Approach 3-2: Intelligently Build a Subsequence (use std::lower_bound)
class Solution {
  public:
    int lengthOfLIS(vector<int>& nums)
    {
        std::vector<int> subs{ nums.front() };

        const auto len_nums = nums.size();
        for (const auto num : nums) {

            if (subs.back() < num) {
                subs.push_back(num);
            }
            else {
                *std::lower_bound(subs.begin(), subs.end(), num) = num;
            }
        }

        return subs.size();
    }
};
//*/