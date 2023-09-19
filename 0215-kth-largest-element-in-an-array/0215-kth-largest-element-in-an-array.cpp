class Solution {
  private:
    template <typename U>
    int findKthLargestHelper(const std::vector<int>& nums, U comp, const int k)
    {
        const auto len_nums = static_cast<int>(nums.size());

        std::priority_queue<int, std::vector<int>, U> pq(comp);

        for (auto n = 0; n != len_nums; ++n) {

            pq.push(nums[n]);

            if (len_nums < n + k) {
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