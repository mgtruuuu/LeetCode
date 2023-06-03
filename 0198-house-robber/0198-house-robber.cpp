class Solution {
  public:
    int rob(vector<int>& nums)
    {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        std::queue<int> queue_part;

        queue_part.push(nums[0]);
        queue_part.push(nums[0] < nums[1] ? nums[1] : nums[0]);

        for (std::size_t idx = 2; idx != nums.size(); ++idx) {

            const auto& queue_front = queue_part.front();
            const auto& queue_back = queue_part.back();

            const auto input = (queue_front + nums[idx] < queue_back ? queue_back : queue_front + nums[idx]);

            queue_part.pop();
            queue_part.push(input);
        }

        return queue_part.back();
    }
};