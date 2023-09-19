class Solution {
  public:
    int findKthLargest(vector<int>& nums, int k)
    {
        const auto len_nums = static_cast<int>(nums.size());

        if (k <= len_nums + 1 - k) {

            std::priority_queue<int> pq;

            for (auto n = 0; n != len_nums; ++n) {

                pq.push(nums[n]);
                
                if (len_nums < n + k) {
                    pq.pop();
                }
            }

            return pq.top();
        }
        else {

            k = len_nums + 1 - k;

            std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

            for (auto n = 0; n != len_nums; ++n) {

                pq.push(nums[n]);
                
                if (len_nums < n + k) {
                    pq.pop();
                }
            }

            return pq.top();
        }
    }
};