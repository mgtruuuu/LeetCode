class Solution {
  private:
    int maxDiff(std::vector<int>& nums, int left, int right)
    {
        if (left == right) {
            return nums[left];
        }

        int scoreByLeft = nums[left] - maxDiff(nums, left + 1, right);
        int scoreByRight = nums[right] - maxDiff(nums, left, right - 1);

        return std::max(scoreByLeft, scoreByRight);
    }

  public:
    bool predictTheWinner(std::vector<int>& nums)
    {
        int n = nums.size();

        return maxDiff(nums, 0, n - 1) >= 0;
    }
};
