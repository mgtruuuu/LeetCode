/*
class Solution {
  private:
    template <typename U>
    int findKthLargestHelper(const std::vector<int>& nums, U comp, const int k)
    {
        const auto len_nums = static_cast<int>(nums.size());

        std::priority_queue<int, std::vector<int>, U> pq(comp);

        for (const auto num : nums) {

            pq.push(num);

            if (static_cast<int>(pq.size()) > len_nums + 1 - k) {
                pq.pop();
            }
        }

        return pq.top();
    }

  public:
    int findKthLargest(vector<int>& nums, int k)
    {
        const auto len_nums = static_cast<int>(nums.size());

        if (k <= len_nums + 1 - k) {
            return findKthLargestHelper(nums, std::less<int>(), k);
        }
        else {
            return findKthLargestHelper(nums, std::greater<int>(), len_nums + 1 - k);
        }
    }
};
*/


class Solution {
  public:
    int findKthLargest(vector<int>& nums, int k)
    {
        const auto len_nums = static_cast<int>(nums.size());

        if (k <= len_nums + 1 - k) {
            std::nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), std::greater<int>{});

            return nums[k - 1];
        }
        else {
            std::nth_element(nums.begin(), nums.begin() + len_nums - k, nums.end());

            return nums[len_nums - k];
        }
    }
};