class Solution {
  public:
    int findKthLargest(vector<int>& nums, int k)
    {
        std::make_heap(nums.begin(), nums.end());

        auto count = 0;
        while (count != k - 1) {

            std::pop_heap(nums.begin(), nums.end() - count);

            ++count;
        }

        return nums.front();
    }
};