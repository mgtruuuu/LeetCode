///*
// Approach 1: Bottom-up Dynamic Programming
class Solution {
  public:
    int findNumberOfLIS(vector<int>& nums)
    {
        const auto len_nums = nums.size();

        std::vector<int> lengths(len_nums);
        std::vector<int> counts(len_nums);

        auto max_length = 0;

        for (auto idx_right = std::size_t(0); idx_right != len_nums; ++idx_right) {

            lengths[idx_right] = 1;
            counts[idx_right] = 1;
            for (auto idx_left = std::size_t(0); idx_left != idx_right; ++idx_left) {

                if (nums[idx_left] < nums[idx_right]) {

                    if (lengths[idx_right] < lengths[idx_left] + 1) {

                        lengths[idx_right] = lengths[idx_left] + 1;
                        counts[idx_right] = counts[idx_left];
                    }
                    else if (lengths[idx_right] == lengths[idx_left] + 1) {
                        counts[idx_right] += counts[idx_left];
                    }
                }
            }

            if (max_length < lengths[idx_right]) {
                max_length = lengths[idx_right];
            }
        }

        
        
        auto sum_counts = 0;
        for (auto idx = std::size_t(0); idx != len_nums; ++idx) {
            if (lengths[idx] == max_length) {
                sum_counts += counts[idx];
            }
        }

        return sum_counts;
    }
};
//*/


/*
// Approach 2: Top-down Dynamic Programming (Memoization)
class Solution {
  private:
    void calculateDP(const std::size_t idx_right, std::vector<int>& nums, std::vector<int>& lengths,
                     std::vector<int>& counts)
    {
        if (lengths[idx_right] != 0) {
            return;
        }

        lengths[idx_right] = 1;
        counts[idx_right] = 1;
        for (auto idx_left = std::size_t(0); idx_left != idx_right; ++idx_left) {

            if (nums[idx_left] < nums[idx_right]) {

                calculateDP(idx_left, nums, lengths, counts);

                if (lengths[idx_right] < lengths[idx_left] + 1) {

                    lengths[idx_right] = lengths[idx_left] + 1;
                    counts[idx_right] = counts[idx_left];
                }
                else if (lengths[idx_right] == lengths[idx_left] + 1) {
                    counts[idx_right] += counts[idx_left];
                }
            }
        }
    }

  public:
    int findNumberOfLIS(vector<int>& nums)
    {
        const auto len_nums = nums.size();

        std::vector<int> lengths(len_nums, 0);
        std::vector<int> counts(len_nums, 0);

        calculateDP(len_nums - 1, nums, lengths, counts);

        auto max_length = 0;
        for (auto idx = std::size_t(0); idx != len_nums; ++idx) {

            calculateDP(idx, nums, lengths, counts);
            if (max_length < lengths[idx]) {
                max_length = lengths[idx];
            }
        }

        auto sum_counts = 0;
        for (auto idx = std::size_t(0); idx != len_nums; ++idx) {
            if (lengths[idx] == max_length) {
                sum_counts += counts[idx];
            }
        }

        return sum_counts;
    }
};
*/