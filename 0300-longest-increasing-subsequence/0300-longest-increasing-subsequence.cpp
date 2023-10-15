/*
// Approach 1: Dynamic Programming
class Solution {
  public:
    int lengthOfLIS(vector<int>& nums)
    {
        const auto len_nums = nums.size();

        auto res = INT_MIN;
        
        std::vector<int> dps(len_nums);

        for (auto idx_right = std::size_t(0); idx_right != len_nums; ++idx_right) {

            dps[idx_right] = 1;

            for (auto idx_left = std::size_t(0); idx_left != idx_right; ++idx_left) {
                
                if (nums[idx_left] < nums[idx_right] && dps[idx_right] < dps[idx_left] + 1) {
                    dps[idx_right] = dps[idx_left] + 1;
                }
            }
            
            if (res < dps[idx_right]) {
                res = dps[idx_right];
            }
        }

        return res;
    }
};
*/


/*
// Approach 2 - 1: Intelligently Build a Subsequence (use while)
class Solution {
  public:
    int lengthOfLIS(vector<int>& nums)
    {
        std::vector<int> subs{ nums.front() };

        const auto len_nums = nums.size();
        for (auto idx = std::size_t(1); idx != len_nums; ++idx) {

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
// Approach 2 - 2: Intelligently Build a Subsequence (use std::lower_bound)
class Solution {
  public:
    int lengthOfLIS(vector<int>& nums)
    {
        std::vector<int> subs{ nums.front() };

        const auto len_nums = nums.size();
        for (auto idx = std::size_t(1); idx != len_nums; ++idx) {

            if (subs.back() < nums[idx]) {
                subs.push_back(nums[idx]);
            }
            else {
                const auto it = std::lower_bound(subs.begin(), subs.end(), nums[idx]);
                *it = nums[idx];
            }
        }

        return subs.size();
    }
};
*/



///*
// Approach 3: Improve With Binary Search
class Solution {
  private:
    std::size_t binarySearch(std::vector<int>& subs, int num)
    {
        auto idx_left = 0;
        auto idx_right = static_cast<int>(subs.size()) - 1;

        while (idx_left <= idx_right) {

            const auto idx_mid = static_cast<int>((idx_left + idx_right) * 0.5);

            if (subs[idx_mid] >= num) {
                idx_right = idx_mid - 1;
            }
            else {
                idx_left = idx_mid + 1;
            }
        }

        return idx_left;
    }

  public:
    int lengthOfLIS(vector<int>& nums)
    {
        std::vector<int> subs{ nums.front() };

        const auto len_nums = nums.size();
        for (auto idx = std::size_t(1); idx != len_nums; ++idx) {

            const auto idx_insert = binarySearch(subs, nums[idx]);

            if (idx_insert == subs.size()) {
                subs.push_back(nums[idx]);
            }
            else {
                subs[idx_insert] = nums[idx];
            }
        }

        return subs.size();
    }
};
//*/