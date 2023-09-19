class Solution {
  private:
    template <typename U>
    int findKthLargestHelper(const std::vector<int>& nums, U comp, const int k)
    {
        const auto len_nums = static_cast<int>(nums.size());

        std::priority_queue<int, std::vector<int>, U> pq(comp);

        for (const auto num : nums) {
            
            pq.push(num);
            
            if (static_cast<int>(pq.size()) > k) {
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
            return findKthLargestHelper(nums, std::greater<int>(), k);
        }
        else {
            return findKthLargestHelper(nums, std::less<int>(), len_nums + 1 - k);
        }
    }
};